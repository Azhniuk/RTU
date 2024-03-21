#pragma once
#ifndef PLAYER
#define PLAYER
#include <string>
using namespace std;

#include "PlayerSpec.h"

class Player
{
public:
	Player(): 
		_nick{ Nick::ANY }, 
		_play{ false }, 
		_spec{ }
	{}
	
	enum class Nick { ANY, Andris, Oleh, Dita, Janis, Ihor, Ivars };
	static constexpr string_view Nick_str[]{ "Any", "Andris", "Oleh", "Dita", "Janis", "Ihor", "Ivars" };

	Player( Nick nick, bool play, const PlayerSpec& spec);
	

	bool get_play() const { return _play; }
	Player::Nick get_nick() const { return _nick; }
	string_view get_nick_str() const { return Nick_str[(size_t)_nick]; }
	const PlayerSpec& get_spec() const { return _spec; }


private:
	Player::Nick _nick;
	bool _play;
	PlayerSpec _spec;
};

#endif