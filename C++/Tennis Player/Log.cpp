#include "Log.h"
#include <cmath>
//functions 

void Log::add_item(const Player& new_item)
{
    auto found{ this->find_all_items(*new_item.get_spec()) };

    for (auto found_item : found)
        if (found_item.get_nick() == new_item.get_nick())
            return;

    _items.push_back(new_item);
}

Player Log::find_item(const PlayerSpec& otherSpec) const
{
    auto found{ this->find_all_items(otherSpec) };

    if (!found.empty())
        return found[0];

    return Player{};
}

vector<Player> Log::find_all_items(const PlayerSpec& otherSpec) const
{
    vector<Player> found;

    for (auto item : _items)
        if (item.get_spec()->matches(otherSpec))
            found.push_back(item);

    return found; 
}



