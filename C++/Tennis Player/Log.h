#ifndef LOG
#define LOG

#include <memory>
#include "Player.h" 
#include "PlayerSpec.h" 
#include <vector>

class Log
{
public:
   Player get_item(size_t i) const { return (i < _items.size()) ? _items[i] : Player{}; }
   size_t get_count() const { return _items.size(); }
   void add_item(const Player& new_item);
   Player find_item(const PlayerSpec& otherSpec) const;
   
   vector<Player>::const_iterator begin() const { return _items.begin(); }
   vector<Player>::const_iterator end() const { return _items.end(); }
   vector<Player> find_all_items(const PlayerSpec& otherSpec) const;

private:
    vector<Player> _items;


};


#endif

// Log() : _count{ 0 } {}


//    
 //Player::Nick nick, bool play, spcPlayerSpec spec


    //Player find_item(const Player& query) const;
    //Player find_item(const PlayerSpec& spec_query) const;
