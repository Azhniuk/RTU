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
    // (replace parameters to match your property types and identifiers)
    void add_item(double _height, double _weight, string _nick, int _experience, bool _play);

    // Looks for a matching abstraction object and returns the first found or default object
    Player find_item(Player query);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Player _items[Log::MAX_SIZE];

    //objects in the array _items
    size_t _count;
};

#endif
