#pragma once
#ifndef PLAYER
#define PLAYER
#include <string>
using namespace std;

#include "PlayerSpec.h"

class Player
{
public:
	Player() = default;
	enum class Nick { ANY, Andris, Oleh, Dita, Janis, Ihor, Ivars, Keks, Andrii, Bars};
	static constexpr string_view Nick_str[]{ "Any", "Andris", "Oleh", "Dita", "Janis", "Ihor", "Ivars", "Keks", "Andrii", "Bars"};

	Player( Nick nick, bool play, spcPlayerSpec spec);
	

	bool get_play() const { return _play; }
	Player::Nick get_nick() const { return _nick; }
	string_view get_nick_str() const { return Nick_str[(size_t)_nick]; }
	//const PlayerSpec& get_spec() const { return _spec; }
	spcPlayerSpec get_spec() const { return _spec; }


private:
	Player::Nick _nick;
	bool _play;
	spcPlayerSpec _spec;
};

#endif