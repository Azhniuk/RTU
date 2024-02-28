#include "Player.h"

void Player::init(double height, double weight, string nick, int experience, bool play)
{
	_height = height;
	_weight = weight;
	_nick = nick;
	_experience = experience;
	_play = play;
}