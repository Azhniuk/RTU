#include <iostream>
#include "Player.h"
#include "Log.h"

#include <cassert>

using namespace std;

void show(const Player & item)
{
    auto is_p{ item.get_spec() };

    if (!is_p)
        is_p.reset(new PlayerSpec());


    cout << "The sport is "
        << is_p->get_sport_str()  << ". Player is: "
        << is_p->get_height() <<"cm, "
        << is_p->get_weight() << "kg.\nName: " 
        << item.get_nick_str() 
        << "; Experience:" << is_p->get_experience_str() 
        << " years.\n" << item.get_play() <<" ==> if plays 1, if no - 0\n" 
        << endl;
}

float max_weight(const Log& log)
{
    float max = 0;
    for (int i = 1; i < log.get_count(); i++)
    {
        auto spec = log.get_item(i).get_spec();
 
        if (spec->get_weight() > max)
        {
            max = spec->get_weight();
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
        auto spec = log.get_item(i).get_spec(); 
        if (spec) 
            sum += spec->get_height();
    }
    return sum / log.get_count();
}


int main()
{
    Log log;

  
    //add people
    log.add_item(Player::Nick::Andris, true, make_shared<PlayerSpec>( 167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box ));
    log.add_item(Player::Nick::Oleh, false, make_shared<PlayerSpec>(120,  80.3, PlayerSpec::Experience::two, PlayerSpec::Sport::swimming ));
    log.add_item(Player::Nick::Dita, true, make_shared<PlayerSpec>(167.5, 80.7, PlayerSpec::Experience::five, PlayerSpec::Sport::box ));
    log.add_item(Player::Nick::Janis, true, make_shared<PlayerSpec>(90,  8.4, PlayerSpec::Experience::zero, PlayerSpec::Sport::running ));
    
    //add Ihor
    spcPlayerSpec spec_Ihor(new PlayerSpec( 210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running));
    log.add_item(Player::Nick::Ihor, true, spec_Ihor);

    log.add_item(Player::Nick::Ivars, false, make_shared<PlayerSpec>( 190,  89.6, PlayerSpec::Experience::three, PlayerSpec::Sport::swimming ));

    //check if all items 
    assert(log.get_count() == 6);

    spcPlayerSpec spec_cat(new PlayerSpec( 60.7, 8, PlayerSpec::Experience::five, PlayerSpec::Sport::skiing));
    log.add_item(Player::Nick::Keks, true, spec_cat);
    log.add_item(Player::Nick::Bars, true, spec_cat);

    assert(log.get_count() == 8);

    show(log.find_item(PlayerSpec{ 210.9, 100.3, PlayerSpec::Experience::ten, PlayerSpec::Sport::running }));

    cout << "\n" << "Max weight is: " << endl;
    cout<<max_weight(log)<<endl;
    cout << "Average height: " << average_height(log) << endl;
    return 0;
}