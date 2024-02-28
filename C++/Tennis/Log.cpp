#include "Log.h"
#include <cmath>

    // The parameters must match with the class declaration
    void Log::add_item(double _height, double _weight, string _nick, int _experience, bool _play)
{
    if (_count < Log::MAX_SIZE)
    {
        Player new_item;
        new_item.init(_height, _weight, _nick,_experience,_play);
        _items[_count] = new_item;
        _count++;
    }
}

    Player Log::find_item(Player query)
{
    for (size_t i = 0; i < _count; i++)
    {
        // for integer or boolean type property
        if (query.get_experience() != 0
            && query.get_experience() != _items[i].get_experience())
            continue;
        if (query.get_play() != 0
            && query.get_play() != _items[i].get_play())
            continue;

        // for string type property
        if (query.get_nick() != ""
            && query.get_nick() != _items[i].get_nick())
            continue;

        // for other types see in the demo solution
        // for double type
        constexpr double epsil{ 0.005 };
        if (query.get_height() != 0.0
            && epsil < std::abs(query.get_height() - _items[i].get_height()))
            continue;

        if (query.get_weight() != 0.0
            && epsil < std::abs(query.get_weight() - _items[i].get_weight()))
            continue;

        return _items[i];
    }

    return Player{}; 
}