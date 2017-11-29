// rollofdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/


#include "rollofdice.h"
#include <algorithm>

RollOfDice::RollOfDice() :
	rod(std::vector<Dice>()) {}

RollOfDice::RollOfDice(const std::vector<Colour> &colours) :
	rod(std::vector<Dice>()) {
	for (Colour c : colours) {
		rod.emplace_back(Dice(c));
	}
}

void RollOfDice::addDice(const Colour &c) {
	rod.emplace_back(Dice(c));
}

RollOfDice RollOfDice::getPair(const std::vector<Colour> &colours)
	{
	if (!colours.size() != 2)
		throw "whoops! can't get a pair that's not size 2";
		
	RollOfDice pairOfDice;
	for (auto &d : *this) {
		if (std::find(colours.begin(), colours.end(), d.getColour()) != colours.end()) {
				pairOfDice.addDice(d.getColour());
		}
	}
	return pairOfDice;
}

void RollOfDice::roll() {
	for (auto& d : rod) {
		d.roll();
	}
}

RollOfDice::operator int() {
	int total = 0;
	for (auto &d : rod) {
		total += d.getValue();
	}
	return total;
}

std::ostream& operator<<(std::ostream& os, const RollOfDice& rod) {
	for (const auto& d : rod) {
		os << d;
		os << std::endl;
	}
	return os;
}

