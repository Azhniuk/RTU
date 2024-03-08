#include "Player.h"

void Player::init(double height, double weight, Player::Nick nicks, Player::Experience experiences, bool play)
{
	_height = height;
	_weight = weight;
	_nicks = nicks;
	_experiences = experiences;
	_play = play;
}