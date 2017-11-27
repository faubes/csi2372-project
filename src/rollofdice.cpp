// rollofdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/


#include "rollofdice.h"

RollOfDice::RollOfDice(const std::vector<Colour> &colours) :
 rod(std::vector<Dice>()) {
		for (c : colours) {
		rod.emplace_back(Dice(c));
	}
}
		
void RollOfDice::roll() {
	for (auto& d : rod) {
		d.roll();
	}
}

std::ostream& operator<<(std::ostream& os, const RollOfDice& rod) {
	for (const auto& d : rod) {
		os << d;
		os << std::endl;
	}
	return os;
}

