#include "Log.h"
#include <cmath>

void Log::add_item(double height, double weight, Player::Nick nicks, Player::Experience experiences, bool play)
{
    Player new_item;
    new_item.init(height, weight, nicks, experiences, play);

    if (find_item(new_item).get_height() == 0 && _count < Log::MAX_SIZE)
    {
        _items[_count] = new_item;
        _count++;
    }
}

Player Log::find_item(const Player& query) const
{
    for (size_t i = 0; i < _count; i++)
    {
        // for integer or boolean 
        if (query.get_experience() != Player::Experience::ANY
            && query.get_experience() != _items[i].get_experience())
            continue;
        if (query.get_play() != 0
            && query.get_play() != _items[i].get_play())
            continue;

        // for string
        if (query.get_nick() != Player::Nick::ANY
            && query.get_nick() != _items[i].get_nick())
            continue;

        // for double
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