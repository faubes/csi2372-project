// dice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#include "randomdice.h"
#include "colour.h"

class Dice {
	const Colour c;
	int face;
	// Dice();
	Dice(const Colour _c);
	roll();
	friend ostream& operator<<(ostream& os, const Dice& d);
}
