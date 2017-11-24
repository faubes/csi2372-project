// rollofdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// #define TEST_ROLLOFDICE

#include "rollofdice.h"

RollOfDice::RollOfDice(const std::vector<Colour> &colours) {
	rod = std::vector<Dice>(colours.size());
	for (c : colours) {
		rod.emplace_back(Dice(c));
	}
}
		
void RollOfDice::roll() {
	for (auto& d : rod) {
		d.roll();
	}
}

ostream& operator<<(ostream& os, const RollOfDice& rod) {
	for (const auto& d : rod) {
		os << d;
		os << std::endl;
	}
	return os;
}

#ifdef TEST_ROLLOFDICE
#include <iostream>
int main() {
    std::vector<Colour> c = {Colour::RED, Colour::YELLOW};
    RollOfDice rd(c);
    rd.roll();
    std::cout << rd << std::endl;
}
#endif
