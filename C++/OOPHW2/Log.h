#ifndef LOG
#define LOG

#include "Player.h" 

class Log
{
public:
    void init() { _count = 0; }

    size_t get_count() { return _count; }

    // Returns stored abstraction object by its index or default object if index is invalid
    Player get_item(size_t i) { return (i < _count) ? _items[i] : Player{}; }

    // new abstraction object in an array _items
    void add_item(double _height, double _weight, string _nick, int _experience, bool _play);

    Player find_item(Player query);

private:
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Player _items[Log::MAX_SIZE];

    size_t _count;
};

#endif
