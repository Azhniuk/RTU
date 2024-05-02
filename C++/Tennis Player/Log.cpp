#include "Log.h"
#include <cmath>


void Log::add_item(Player::Nick nick, bool play, spcPlayerSpec spec)
{
     if (_count < Log::MAX_SIZE)
    {
         Player new_item(nick, play, spec);
        _items[_count] = new_item;
        _count++;
    }
}

Player Log::find_item(const Player& query) const
{
    auto query_spec_p{ query.get_spec() };

    // Check match of all Player properties:
    for (size_t i = 0; i < _count; i++)
    {
        if (query.get_play() != 0
            && query.get_play() != _items[i].get_play())
            continue;

        // for string
        if (query.get_nick() != Player::Nick::ANY
            && query.get_nick() != _items[i].get_nick())
            continue;

        auto item_spec_p{ _items[i].get_spec() };
        if (query_spec_p && item_spec_p && item_spec_p->matches(*query_spec_p))
        {
            return _items[i];
        }
    }

    return Player{};
}


Player Log::find_item(const PlayerSpec& query_spec) const
{
    for (size_t i = 0; i < _count; i++)
    {
        auto item_spec_p{ _items[i].get_spec() };


        if (item_spec_p && item_spec_p->matches(query_spec))
        {
            return _items[i];
        }
    }

    return Player{}; 
}




