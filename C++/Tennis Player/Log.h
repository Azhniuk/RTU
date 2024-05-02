#ifndef LOG
#define LOG

#include <memory>
#include "Player.h" 
#include "PlayerSpec.h" 

class Log
{
public:
    Log(): _count{0} {}

    size_t get_count() const { return _count; }

    Player get_item(size_t i) const { return (i < _count) ? _items[i] : Player{}; }

    void add_item(Player::Nick nick, bool play, spcPlayerSpec spec);


    Player find_item(const Player& query) const;
    Player find_item(const PlayerSpec& spec_query) const;

private:
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Player _items[Log::MAX_SIZE];

    size_t _count;
};


#endif
