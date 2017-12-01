// qwintoplayer.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// The class QwintoPlayer holds a QwintoScoreSheet and implements the functions
// inputBeforeRoll and inputAfterRoll.

#include "qwintoplayer.h"
#include "gameui.h"
#include "colour.h"
#include <string>

QwintoPlayer::QwintoPlayer(const std::string& n) : Player(n), qws(n) {}

void QwintoPlayer::inputBeforeRoll(RollOfDice& rod) {
	std::vector<Colour> colours;
	bool valid = false;
	while (!valid) {
		for (Colour c : qwintoColours) {
			std::string msg("Roll " + colour_to_string(c) + " dice?");
			if (getYesNo(std::cout, std::cin, msg)) {
				colours.emplace_back(c);
			}
		}
		if (colours.size() == 0) {
			std::cout << "You need to roll at least one dice!" << std::endl;
		}
		else {
			valid = true;
			rod = RollOfDice(colours);
			rod.roll();
		}
	}
	this->setActive(true);
}

void QwintoPlayer::inputAfterRoll(const RollOfDice& rod) {
	if (this->qws.isFailedThrow(rod)) {
		if (isActive()) {
			std::cout << "Uh oh! Failed throw!" << std::endl;
			this->qws.incrementFailedThrows();
			this->setActive(false);
		}
		else {
			std::cout << "Too bad. You can't use this roll." << std::endl;
		}
		return;
	}
	bool valid = false;
	while (!valid) {

	}
}
