#include "PlayerSpec.h"
#include <string> 
#define strcasecmp _stricmp

ostream& operator<<(ostream& os, const PlayerSpec& spec)
{
    spec.send_to(os);
    return os;
}

ostream& operator<<(ostream& os, PlayerSpec::Experience experiences)
{
    return os << PlayerSpec::Experience_str[static_cast<size_t>(experiences)];
}

ostream& operator<<(ostream& os, PlayerSpec::Sport sports)
{
    return os << PlayerSpec::Sport_str[static_cast<size_t>(sports)];
}

void PlayerSpec::send_to(ostream& os) const {
    os << _height << csv_delimiter
        << _weight << csv_delimiter
        << _experiences << csv_delimiter
        << _sports;
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
