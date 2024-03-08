#pragma once
#ifndef PLAYER
#define PLAYER
#include <string>
using namespace std;

class Player
{
public:
	enum class Nick { ANY, Andris, Oleh, Dita, Janis, Ihor, Ivars };
	static constexpr string_view Nick_str[]{ "Any", "Andris", "Oleh", "Dita", "Janis", "Ihor", "Ivars" };

	enum class Experience { ANY, zero, two, three, five, ten };
	static constexpr string_view Experience_str[]{ "Any", "0", "2", "3", "5", "10" };

	void init(double height, double weight, Player::Nick nicks, Player::Experience experiences, bool play);
	float get_height() const { return _height; }
	float get_weight() const { return _weight; }
	bool get_play() const { return _play; }
	Player::Nick get_nick() const { return _nicks; }
	Player::Experience get_experience() const { return _experiences; }
	string_view get_nick_str() const { return Nick_str[(size_t)_nicks]; }
	string_view get_experience_str() const { return Experience_str[(size_t)_experiences]; }

private:
	Player::Nick _nicks;
	Player::Experience _experiences;
	double _height;
	double _weight;
	bool _play;
};

#endif