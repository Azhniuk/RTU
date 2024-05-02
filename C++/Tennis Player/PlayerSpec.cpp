#include "PlayerSpec.h"

bool PlayerSpec::matches(const PlayerSpec& otherSpec) const
{
    if (this == &otherSpec) // if comparing to self
        return true;

    auto result{ true };

    // Check each BicycleSpec property, e.g.:

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


