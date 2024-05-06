#pragma once
#ifndef PLAYER_SPEC
#define PLAYER_SPEC

#include <cstddef>
#include <memory>
#include <iostream>

using namespace std;

class PlayerSpec
{
public:
    void send_to( ostream& os) const;
    bool matches(const PlayerSpec& otherSpec) const;

    enum class Experience { ANY, zero, two, three, five, ten };
    static constexpr string_view Experience_str[]{ "Any", "0", "2", "3", "5", "10" };

    enum class Sport { ANY, swimming, running, box, skiing };
    static constexpr string_view Sport_str[]{ "Any", "swimming", "running", "box", "skiing" };

    void recv_from(istream& is);
    friend istream& operator>>(istream& is, PlayerSpec& spec);

 
    PlayerSpec()
        : _height{ 0.0 }, _weight{ 0.0 }, _experiences{ Experience::ANY }, _sports{ Sport::ANY }
    { }

    PlayerSpec(double height, double weight, Experience experiences, Sport sports)
        : _height{ height }, _weight{ weight }, _experiences{ experiences }, _sports{ sports }
    { }


private:
    double _height;
    double _weight;
    PlayerSpec::Experience _experiences;
    PlayerSpec::Sport _sports;
};

typedef shared_ptr<const PlayerSpec> spcPlayerSpec;

ostream& operator<<(ostream& os, PlayerSpec::Experience experiences);
//istream& operator>>(istream& is, PlayerSpec::Experience experiences);

ostream& operator<<(ostream& os, PlayerSpec::Sport sports);
istream& operator>>(istream& is, PlayerSpec::Sport sports);

ostream& operator<<(ostream& os, const PlayerSpec& spec);

constexpr auto csv_delimiter{ ';' };


#endif