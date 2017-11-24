// rollofdice.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef ROLLOFDICE
#define ROLLOFDICE

#include "dice.h"
#include "colour.h"
#include <vector>
#include <iostream>

using std::ostream;

class RollOfDice {
	std::vector<Dice> rod;

	public:
	
	RollOfDice(const std::vector<Colour> &colours);
	void roll();

	using iterator = std::vector<Dice>::iterator;
	using const_iterator = std::vector<Dice>::const_iterator;

	iterator begin() { return rod.begin(); }
	iterator end() { return rod.end(); }
	const_iterator begin() const { return rod.begin(); }
	const_iterator end() const { return rod.end(); }
	const_iterator cbegin() const { return rod.cbegin(); }
	const_iterator cend() const { return rod.cend(); }
  
	friend ostream& operator<<(ostream& os, const Dice& d);
	
};

#endif
