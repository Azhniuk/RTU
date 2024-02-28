#include <iostream>
#include "Player.h"
#include "Log.h"

#include <cassert>

using namespace std;

void show(Player item)
{
    cout << item.get_height() << "'" << item.get_weight() << "' " << item.get_nick() << "'" << item.get_experience()<<" years of experience '" << item.get_play() << endl;
}

int main()
{
    Log log;

    log.init();

   // _height, double _weight, string _nick, int _experience, bool _play
    log.add_item(167.5, 80.7, "Andris", 5, true);
    log.add_item(120, 80.3, "Oleh", 2, false);
    log.add_item(180.5, 50.4, "Dita", 3, true);
    log.add_item(90, 8.4, "Janis", 0, false);
    log.add_item(210.9, 100.3, "Ihor", 10, true);
    log.add_item(190, 89.6, "Ivars", 3, true);

//check if all items 
    assert(log.get_count() == 6);
  
    Player qry;
    qry.init(167.5, 80.7, "Andris", 5, true);
    show(log.find_item(qry));
    assert(log.find_item(qry).get_experience() == 5);
       
    qry.init(190, 89.6, "Ivars", 3, true);
    show(log.find_item(qry));
    assert(log.find_item(qry).get_experience() == 3);

    //tests with different query values
    //Finds an item if change Boolean value??
    qry.init(167.5, 80.7, "Andris", 5, false);
    show(log.find_item(qry));
    assert(log.find_item(qry).get_nick() == "Andris");
    assert(log.find_item(qry).get_play() == true);


    //Does not find if change other things
    qry.init(167.5, 80.7, "Oleh", 5, true);
    show(log.find_item(qry));
    assert(log.find_item(qry).get_nick() == "Oleh");
    assert(log.find_item(qry).get_play() == false);

    // tests for nonmatching object
    qry.init(90, 80.7, "Solomija", 5, true);
    show(log.find_item(qry));

    return 0;
}