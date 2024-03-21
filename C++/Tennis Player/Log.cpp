#include "Log.h"
#include <cmath>


void Log::add_item(Player::Nick nick, bool play, const PlayerSpec& spec)
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
    auto query_spec{ query.get_spec() }; 

    for (size_t i = 0; i < _count; i++)
    {
        if (query.get_play() != 0
            && query.get_play() != _items[i].get_play())
            continue;

        // for string
        if (query.get_nick() != Player::Nick::ANY
            && query.get_nick() != _items[i].get_nick())
            continue;


        auto item_spec{ _items[i].get_spec() };

       // for experience
       if (query_spec.get_experience() != PlayerSpec::Experience::ANY
           && query_spec.get_experience() != item_spec.get_experience())
                continue;

       //for height
        constexpr double epsil{ 0.005 };
       if (query_spec.get_height() != 0.0
           && epsil < std::abs(query_spec.get_height() - item_spec.get_height()))
           continue;

       //for weight
       if (query_spec.get_weight() != 0.0
           && epsil < std::abs(query_spec.get_weight() - item_spec.get_weight()))
           continue;

       //for sport
       if (query_spec.get_sport() != PlayerSpec::Sport::ANY
           && query_spec.get_sport() != item_spec.get_sport())
           continue;

        return _items[i];
    }

    return Player{};
}


Player Log::find_item(const PlayerSpec& query_spec) const
{
    for (size_t i = 0; i < _count; i++)
    {
        auto item_spec{ _items[i].get_spec() };

        // for experience
        if (query_spec.get_experience() != PlayerSpec::Experience::ANY
            && query_spec.get_experience() != item_spec.get_experience())
            continue;

        //for height
        constexpr double epsil{ 0.005 };
        if (query_spec.get_height() != 0.0
            && epsil < std::abs(query_spec.get_height() - item_spec.get_height()))
            continue;

        //for weight
        if (query_spec.get_weight() != 0.0
            && epsil < std::abs(query_spec.get_weight() - item_spec.get_weight()))
            continue;

        //for sport
        if (query_spec.get_sport() != PlayerSpec::Sport::ANY
            && query_spec.get_sport() != item_spec.get_sport())
            continue;


        return _items[i];
    }

    return Player{}; 
}












/*  // */

/* // */
