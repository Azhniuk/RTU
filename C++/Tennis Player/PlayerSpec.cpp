#include "PlayerSpec.h"
#include <string> 
#define strcasecmp _stricmp

ostream& operator<<( ostream& os, const PlayerSpec& spec)
{
    spec.send_to(os);
    return os;
}

ostream& operator<<( ostream& os, PlayerSpec::Experience experiences)
{
    return os << PlayerSpec::Experience_str[static_cast<size_t>(experiences)];
}

ostream& operator<<( ostream& os, PlayerSpec::Sport sports)
{
    return os << PlayerSpec::Sport_str[static_cast<size_t>(sports)];
}

void PlayerSpec::send_to( ostream& os) const {
    os << _height << csv_delimiter
        << _weight << csv_delimiter
        << _experiences << csv_delimiter
        << _sports;
}


istream& operator>>(istream& is, PlayerSpec::Experience & experiences)
{
    if (is)
    {
        string tmp;
        getline(is, tmp, csv_delimiter);
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(PlayerSpec::Experience_str) / sizeof(PlayerSpec::Experience_str[0]); i++)
            {
                if (tmp.length() == PlayerSpec::Experience_str[i].length()
                    && 0 == strcasecmp(tmp.c_str(),  string(PlayerSpec::Experience_str[i]).c_str())) // case insensitive comparison
                {
                    experiences = static_cast<PlayerSpec::Experience>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                experiences = PlayerSpec::Experience::ANY;
        }
    }
    return is;
}



istream& operator>>(istream& is, PlayerSpec::Sport sports)
{
    if (is)
    {
        string tmp;
        getline(is, tmp, csv_delimiter);
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(PlayerSpec::Sport_str) / sizeof(PlayerSpec::Sport_str[0]); i++)
            {
                if (tmp.length() == PlayerSpec::Sport_str[i].length()
                    && 0 == strcasecmp(tmp.c_str(),  string(PlayerSpec::Sport_str[i]).c_str())) 
                {
                    sports = static_cast<PlayerSpec::Sport>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                sports = PlayerSpec::Sport::ANY;
        }
    }
    return is;
}



istream& operator>>(istream& is, PlayerSpec& item)
{
    item.recv_from(is);
    return is;
}

void PlayerSpec::recv_from(istream& is)
{
    if (is)
        (is >> _height).ignore();

    if (is)
        (is >> _weight).ignore();

    if (is)
        is >> _experiences;

    if (is)
        is >> _sports;

}



bool PlayerSpec::matches(const PlayerSpec& otherSpec) const
{
    if (this == &otherSpec) // if comparing to self
        return true;

    auto result{ true };

    // Check each PlayerSpec property, e.g.:

    if (result && 0 != otherSpec._height &&
        _height != otherSpec._height)
    {
        result = false;
    }

    if (result && 0 != otherSpec._weight &&
        _weight != otherSpec._weight)
    {
        result = false;
    }

    if (result && otherSpec._experiences != Experience::ANY &&
        _experiences != otherSpec._experiences)
    {
        result = false;
    }

    if (result && otherSpec._sports != Sport::ANY &&
        _sports != otherSpec._sports)
    {
        result = false;
    }

    return result;
}
