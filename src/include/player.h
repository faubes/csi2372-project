// player.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// provides functions for console input and output to a player. 

#ifndef PLAYER
#define PLAYER

#include <string>
#include "rollofdice.h"

class Player {
	bool active = false;
	std::string
	public:
	virtual void inputBeforeRoll(RollOfDice& rod);
	virtual void inputAfterRoll(RollOfDice& rod);
}

#endif
