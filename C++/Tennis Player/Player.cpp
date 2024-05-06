#include "Player.h"
#include <string> 
#define strcasecmp _stricmp

//ctrl+k+c   ctrl+k+u -  multiple comment

Player::Player(Player::Nick nick, bool play, spcPlayerSpec spec)
{	
	_nick = nick;
	_play = play;
	_spec = spec;
	}

ostream& operator<<(ostream& os, const Player& item)
{
    item.send_to(os);
    return os;
}

void Player::send_to(ostream& os) const
{
    os << _nick << csv_delimiter
        << _play << csv_delimiter;

    if (_spec)
    {
        os << csv_delimiter;
        _spec->send_to(os);
    }
}

ostream& operator<<(ostream& os, Player::Nick nick)
{
    return os << Player::Nick_str[static_cast<size_t>(nick)];
}

istream& operator>>(istream& is, Player& item)
{
    item.recv_from(is);
    return is;
}

istream& operator>>(istream& is, Player::Nick nick)
{
    if (is)
    {
        string tmp;
        getline(is, tmp, csv_delimiter);
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(Player::Nick_str) / sizeof(Player::Nick_str[0]); i++)
            {
                if (tmp.length() == Player::Nick_str[i].length()
                    && 0 == strcasecmp(tmp.c_str(), string(Player::Nick_str[i]).c_str()))
                {
                    nick = static_cast<Player::Nick>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                nick = Player::Nick::ANY;
        }
    }
    return is;
}


void Player::recv_from( istream& is)
{
    if (is)
        is >> _nick;

    if (is)
        is >> _play;

    auto temp_spec{  make_shared<PlayerSpec>() };
    is >> *temp_spec; // alternatively: temp_spec->recv_from(is);
    _spec = temp_spec; // replace the specification
}