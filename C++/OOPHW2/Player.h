#pragma once
#ifndef PLAYER
#define PLAYER
#include <string>
using namespace std;

class Player
{
public:
	void init(double _height, double _weight, string _nick, int _experience, bool _play);
	float get_height() { return _height; }
	float get_weight() { return _weight; }
	string get_nick() { return _nick; }
	int get_experience() { return _experience; }
	bool get_play() { return _play; }

private:
	double _height;
	double _weight;
	string _nick;
	int _experience;
	bool _play;
};

#endif