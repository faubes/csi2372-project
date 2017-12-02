// qwintoplayer.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

#include "gameui.h"
#include "player.h"
#include "qwintoscoresheet.h"

class QwintoPlayer : public Player {
        QwintoScoreSheet qws;
    public:
        QwintoPlayer(const std::string& name);
        void inputBeforeRoll(RollOfDice& rod);
        void inputAfterRoll(const RollOfDice& rod);
        void print(std::ostream& myStream) const;
        bool operator!() const {
			return (!qws);
		}
		int getScore() { return qws.setTotal(); }
};

#endif
