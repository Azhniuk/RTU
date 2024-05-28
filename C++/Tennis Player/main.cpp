#include "Player.h"
#include "Log.h"
#include <iostream>
#include <cassert>
#include <algorithm> 

using namespace std;

template <typename T>
void show(const T& item)
{
    cout << item << "\n";
}

bool is_less(const Player& item1, const Player& item2)
{
    return item1.get_score() < item2.get_score();
}

Player max_score(const Log& log)
{
    if (0 == log.get_count())
        throw range_error("There are no items");


    return *std::max_element(log.begin(), log.end(), is_less);
}

class Average
{
public:
    Average() : _sum{ 0.0 }, _count{ 0 } { }
    void operator()(const Player& item)
    {
        _sum += item.get_score();
        _count++;
    }
    double result() const { return _count ? _sum / _count : 0.0; }
private:
    double _sum;
    size_t _count;
};

double avg_height(const Log& log)
{
    return for_each(log.begin(), log.end(), Average()).result();
}

void show_all(const Log& log) {
    for_each(log.begin(), log.end(), show<Player>);
}

void show_all_vector(const vector<Player>& players) {
    for_each(players.begin(), players.end(), show<Player>);
}

int main()
{
    Log log;

    spcPlayerSpec spec_Ihor(new PlayerSpec(210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running));
    Player numberOne(Player::Nick::Ihor, true, 123, spec_Ihor);
    Player numberTwo(Player::Nick::Andris, true, 10, make_shared<PlayerSpec>(167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box));
    Player numberThree(Player::Nick::Oleh, false, 40, make_shared<PlayerSpec>(120, 80.3, PlayerSpec::Experience::two, PlayerSpec::Sport::swimming));
    Player numberFour(Player::Nick::Dita, true, 90, make_shared<PlayerSpec>(167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box));
    Player numberFive(Player::Nick::Janis, true, 59, make_shared<PlayerSpec>(90, 8.4, PlayerSpec::Experience::zero, PlayerSpec::Sport::running));
    Player numberSix(Player::Nick::Ivars, false, 100, make_shared<PlayerSpec>(190, 89.6, PlayerSpec::Experience::three, PlayerSpec::Sport::swimming));

    log.add_item(numberOne);
    log.add_item(numberTwo);
    log.add_item(numberThree);
    log.add_item(numberFour);
    log.add_item(numberFive);
    log.add_item(numberSix);

    assert(log.get_count() == 6);

    spcPlayerSpec spec_cat(new PlayerSpec(60.7, 8, PlayerSpec::Experience::five, PlayerSpec::Sport::skiing));
    Player numberKeks(Player::Nick::Keks, true, 231, spec_cat);
    Player numberBars(Player::Nick::Bars, true, 87, spec_cat);

    log.add_item(numberKeks);
    log.add_item(numberBars);

    assert(log.get_count() == 8);

    show(log.find_item(PlayerSpec{ 210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running }));

    cout << "\nShow all items that match the spec:\n";
    auto items = log.find_all_items(*spec_cat);
    show_all_vector(items);

    cout << "\n" << "max score is: ";
    Player test = max_score(log);
    cout << test.get_score() << endl;
    cout << "average height: " << avg_height(log) << endl;

    cout << "\nAll items: \n";
    show_all(log);
    return 0;
}



