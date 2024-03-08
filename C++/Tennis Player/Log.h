#ifndef LOG
#define LOG

#include "Player.h" 

class Log
{
public:
    void init() { _count = 0; }

    size_t get_count() const { return _count; }

    // Returns stored abstraction object by its index or default object if index is invalid
    Player get_item(size_t i) const { return (i < _count) ? _items[i] : Player{}; }

    // new abstraction object in an array _items
    void add_item(double height, double weight, Player::Nick nicks, Player::Experience experiences, bool play);

    Player find_item(const Player& query) const;

private:
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Player _items[Log::MAX_SIZE];

    size_t _count;
};


#endif
