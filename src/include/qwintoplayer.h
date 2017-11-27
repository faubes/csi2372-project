// qwintoplayer.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// The class QwintoPlayer holds a QwintoScoreSheet and implements the functions
// inputBeforeRoll and inputAfterRoll.

#include "player.h"
#include "qwintoscoresheet.h"

class QwintoPlayer : public Player {
	QwintoScoreSheet scoresheet;
	void inputBeforeRoll(RollOfDice& rod);
	void inputAfterRoll(RollOfDice& rod);
}
