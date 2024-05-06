#ifndef LOG
#define LOG

#include "Player.h" 
#include "PlayerSpec.h" 

#include <memory>
#include <stdexcept>
#include <exception>
#include <string>
using namespace std;


class Log
{
public:
    Log(): _count{0} {}

    Log(const string& csv_file_name)
        : Log() {
        this->load(csv_file_name);
    }

    size_t get_count() const { return _count; }

    const Player& operator[](size_t i) const { return this->get_item(i); }

    const Player& get_item(size_t i) const
    {
        if (i < _count) return _items[i];

        throw out_of_range("Invalid index value.");
    }

    void add_item(Player::Nick nick, bool play, spcPlayerSpec spec);

    Player find_item(const Player& query) const;
    Player find_item(const PlayerSpec& spec_query) const;

    void save(const string& csv_file_name) const;
    void load(const string& csv_file_name);

private:
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Player _items[Log::MAX_SIZE];

    size_t _count;
};


#endif
