#pragma once

#include <cstddef>
#include <string>
#include <memory>
using namespace std;


class PlayerSpec
{
public:
    bool matches(const PlayerSpec& otherSpec) const;

    enum class Experience { ANY, zero, two, three, five, ten };
    static constexpr string_view Experience_str[]{ "Any", "0", "2", "3", "5", "10" };

    enum class Sport { ANY, swimming, running, box, skiing };
    static constexpr string_view Sport_str[]{ "Any", "swimming", "running", "box", "skiing" };

 
    PlayerSpec()
        : _height{ 0.0 }, _weight{ 0.0 }, _experiences{ Experience::ANY }, _sports{ Sport::ANY }
    { }

    PlayerSpec(double height, double weight, Experience experiences, Sport sports)
        : _height{ height }, _weight{ weight }, _experiences{ experiences }, _sports{ sports }//?
    { }


    float get_height() const { return _height; }
    float get_weight() const { return _weight; }
    PlayerSpec::Experience get_experience() const { return _experiences; }
    string_view get_experience_str() const { return Experience_str[(size_t)_experiences]; }

    PlayerSpec::Sport get_sport() const { return _sports; }
    string_view get_sport_str() const { return Sport_str[(size_t)_sports]; }

private:
    double _height;
    double _weight;
    PlayerSpec::Experience _experiences;
    PlayerSpec::Sport _sports;
};

typedef std::shared_ptr<const PlayerSpec> spcPlayerSpec;

