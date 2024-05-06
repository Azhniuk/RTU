#include <iostream>
#include "Player.h"
#include "Log.h"

#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void show(const Player & item)
{
    cout << item << "\n";
}

int main()
{
    Log log;
    spcPlayerSpec spec_Ihor{ new PlayerSpec(210.9, 100, PlayerSpec::Experience::ten, PlayerSpec::Sport::running) };
 
    Player b1 (Player::Nick::Dita, true, spec_Ihor);
    //add Ihor
    Player b2(Player::Nick::Ihor, true, spec_Ihor);

    auto file_name{ "Players.csv" };
    ofstream ofs(file_name);
    if (ofs)
        ofs << b1 << "\n";
    ofs.close();
    cout << "Saved...\n";

    if (ofs)
        ofs << b2 << "\n";
    ofs.close();
    cout << "Saved...\n";

    ifstream ifs(file_name);
    if (ifs)
        ifs >> b2;
    ifs.close();
    cout << "Read...\n"
        << b2 << "\n----\n";

    //add people
    log.add_item(Player::Nick::Andris, true, make_shared<PlayerSpec>(167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box));
    log.add_item(Player::Nick::Oleh, false, make_shared<PlayerSpec>(120, 80.3, PlayerSpec::Experience::two, PlayerSpec::Sport::swimming));
    log.add_item(Player::Nick::Dita, true, make_shared<PlayerSpec>(167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box));
    log.add_item(Player::Nick::Janis, true, make_shared<PlayerSpec>(90, 8.4, PlayerSpec::Experience::zero, PlayerSpec::Sport::running));

    log.add_item(Player::Nick::Ivars, false, make_shared<PlayerSpec>(190, 89.6, PlayerSpec::Experience::three, PlayerSpec::Sport::swimming));
    spcPlayerSpec spec_cat(new PlayerSpec(60.7, 8, PlayerSpec::Experience::five, PlayerSpec::Sport::skiing));
    log.add_item(Player::Nick::Keks, true, spec_cat);
    log.add_item(Player::Nick::Bars, true, spec_cat);
    
    show(log.find_item(*spec_cat));

    auto file{ "items.csv" };
    log.save(file);

    return 0;
}





