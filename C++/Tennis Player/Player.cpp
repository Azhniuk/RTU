#include "Player.h"
#include <string> 
#define strcasecmp _stricmp

Player::Player(Player::Nick nick, bool play,int score, spcPlayerSpec spec)
{
	_nick = nick;
	_play = play;
	_score = score;
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
        << _play << csv_delimiter
        << _score<< csv_delimiter;

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

//ctrl+k+c   ctrl+k+u -  multiple comment
