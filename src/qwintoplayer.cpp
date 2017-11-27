// qwintoplayer.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// The class QwintoPlayer holds a QwintoScoreSheet and implements the functions
// inputBeforeRoll and inputAfterRoll.


QwintoPlayer::QwintoPlayer(const std::string& name) : Player::Player(name) {
	
}

void QwintoPlayer::inputBeforeRoll(RollOfDice& rod);
void QwintoPlayer::inputAfterRoll(RollOfDice& rod);
