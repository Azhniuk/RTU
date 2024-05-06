#pragma once
#ifndef PLAYER
#define PLAYER
#include <string>
#include <iostream>
#include "PlayerSpec.h"
using namespace std;


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
	spcPlayerSpec get_spec() const { return _spec; }

	void send_to( ostream& os) const;
	void recv_from(istream& is);
	friend  istream& operator>>(istream& is, Player& item);


private:
	Player::Nick _nick;
	bool _play;
	spcPlayerSpec _spec;
};

ostream& operator<<( ostream& os, Player::Nick nick);
ostream& operator<<( ostream& os, const Player& item);
//istream& operator>>(istream& is, Player::Nick & nick);

#endif