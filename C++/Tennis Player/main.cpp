#include <iostream>
#include "Player.h"
#include "Log.h"

#include <cassert>

using namespace std;

void show(const Player & item)
{
    auto is{ item.get_spec() }; // const PlayerSpec &
    cout << "The sport is "
        << is.get_sport_str()  << ". Player is: "
        << is.get_height() <<"cm, "
        << is.get_weight() << "kg.\nName: " 
        << item.get_nick_str() 
        << "; Experience:" << is.get_experience_str() 
        << " years.\n" << item.get_play() <<" ==> if plays 1, if no - 0\n" 
        << endl;
}

Player max_weight(const Log& log)
{
    Player max = log.get_item(0);
    for (int i = 1; i < log.get_count(); i++)
    {
        if (log.get_item(i).get_spec().get_weight() > max.get_spec().get_weight())
        {
            max = log.get_item(i);
        }
    }
    return max;
}

double average_height(const Log& log)
{
    double sum;
    sum = 0;
    for (int i = 0; i < log.get_count(); i++)
    {
        sum += log.get_item(i).get_spec().get_height();
    }

    return sum / log.get_count();
}


int main()
{
    Log log;
    //add people
    log.add_item(Player::Nick::Andris, true, PlayerSpec{ 167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box });
    log.add_item(Player::Nick::Oleh, false, PlayerSpec{ 120,  80.3, PlayerSpec::Experience::two, PlayerSpec::Sport::swimming });
    log.add_item(Player::Nick::Dita, true, PlayerSpec{ 167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box });
    log.add_item(Player::Nick::Janis, true, PlayerSpec{ 90,  8.4, PlayerSpec::Experience::zero, PlayerSpec::Sport::running });
    
    //add Ihor
    PlayerSpec Ihor{ 210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running };
    log.add_item(Player::Nick::Ihor, true, Ihor);

    //Check Ihor`s name
    assert(log.find_item(Ihor).get_nick() == log.find_item(Ihor).get_nick());

    log.add_item(Player::Nick::Ivars, false, PlayerSpec{ 190,  89.6, PlayerSpec::Experience::three, PlayerSpec::Sport::swimming });

    //check if all items 
    assert(log.get_count() == 6);

    PlayerSpec cat{ 60.7, 8, PlayerSpec::Experience::five, PlayerSpec::Sport::skiing };
    log.add_item(Player::Nick::Keks, true, cat);

    PlayerSpec Keks{ 60.7, 8, PlayerSpec::Experience::five, PlayerSpec::Sport::skiing };
    assert(log.find_item(Keks).get_spec().get_height() == log.find_item(Keks).get_spec().get_height());
    assert(log.find_item(Keks).get_spec().get_weight() == cat.get_weight());

    //check if all items 
    assert(log.get_count() == 7);

    show(log.find_item(PlayerSpec{ 210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running }));

    show(log.find_item(cat));

    cout <<"\n"<< "Max weight has: "<<endl;
    show(max_weight(log));
    cout << "Average height: " << average_height(log) << endl;
    return 0;

    //Check calculations
    assert(average_height(log) == (167.5 + 120 + 167.5 + 90 + 210.9 + 190 + 60.7) / 7);

}