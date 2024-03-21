#include <iostream>
#include "Player.h"
#include "Log.h"

#include <cassert>

using namespace std;

void show(const Player & item)
{
    cout <<"Player is: "
        << item.get_height() <<"cm, "
        << item.get_weight() << "kg.\nName: " 
        << item.get_nick_str() 
        << "; Experience:" << item.get_experience_str() 
        << " years." << item.get_play() <<" - if plays\n" 
        << endl;
}

Player max_weight(const Log& log)
{
    Player max = log.get_item(0);
    for (int i = 1; i < log.get_count(); i++)
    {
        if (log.get_item(i).get_weight() > max.get_weight())
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
        sum += log.get_item(i).get_height();
    }

    return sum / log.get_count();
}


int main()
{
    Log log;
   // Log() : _count{ 0U } { };

   // log.init();

    // _height, double _weight, string _nick, int _experience, bool _play
    log.add_item(167.5, 80.7, Player::Nick::Andris, Player::Experience::five, true);
    log.add_item(120, 80.3, Player::Nick::Oleh, Player::Experience::two, false);
    log.add_item(180.5, 50.4, Player::Nick::Dita, Player::Experience::three, true);
    log.add_item(90, 8.4, Player::Nick::Janis, Player::Experience::zero, false);
    log.add_item(210.9, 100.3, Player::Nick::Ihor, Player::Experience::ten, true);
    log.add_item(190, 89.6, Player::Nick::Ivars, Player::Experience::three, true);

    //check if all items 
    assert(log.get_count() == 6);

    Player qry;
    qry.init(167.5, 80.7, Player::Nick::Andris, Player::Experience::five, true);
    show(log.find_item(qry));
    //check experience
    //assert(log.find_item(qry).get_experience() == Player::Experience::five);

    qry.init(190, 89.6, Player::Nick::Ivars, Player::Experience::three, true);
    show(log.find_item(qry));
    //check experience
    //assert(log.find_item(qry).get_experience() == Player::Experience::three);

    qry.init(167.5, 80.7, Player::Nick::Andris, Player::Experience::five, false);
    show(log.find_item(qry));
    //check nick and experience
    assert(log.find_item(qry).get_nick() == Player::Nick::Andris);
    assert(log.find_item(qry).get_experience() == Player::Experience::five);

    qry.init(167.5, 80.7, Player::Nick::Oleh, Player::Experience::five, true);
    show(log.find_item(qry));
    //check height, shouldn`t find, so == 0
    assert(log.find_item(qry).get_height() == 0);

    // tests for nonmatching object
    qry.init(90, 80.7, Player::Nick::ANY, Player::Experience::five, true);
    show(log.find_item(qry));
    assert(log.find_item(qry).get_experience() == Player::Experience::ANY);

    log.add_item(200, 100, Player::Nick::Ihor, Player::Experience::ten, true);
    log.add_item(200, 100, Player::Nick::Ihor, Player::Experience::ten, true);
    assert(log.get_count() == 7);


    cout <<"\n"<< "Max weight: "<<endl;
    show(max_weight(log));
    cout << "Average height: " << average_height(log) << endl;
    return 0;
}