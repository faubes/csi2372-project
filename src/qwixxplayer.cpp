// qwixxplayer.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// The class QwintoPlayer holds a QwintoScoreSheet and implements the functions
// inputBeforeRoll and inputAfterRoll.

#include "qwixxplayer.h"
#include "colour.h"
#include <string>

QwixxPlayer::QwixxPlayer(const std::string& n) : Player(n), qws(n) {}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rod) { }

void QwixxPlayer::inputAfterRoll(const RollOfDice& rod) { }

void QwixxPlayer::print(std::ostream& os) const {
    os << this->qws;
}
