// qwixxplayer.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef QWIXXPLAYER
#define QWIXXPLAYER

#include "gameui.h"
#include "player.h"
#include "qwixxscoresheet.h"
#include <set>

class QwixxPlayer : public Player {
        
        QwixxScoreSheet qws;
        static std::vector<Colour> availableColours;
		void removeLockedDice();
		void doBonusScore(const RollOfDice& rod, std::vector<Colour> rows);
		void doScore(const RollOfDice& rod, std::vector<Colour> rows);
        
    public:
		QwixxPlayer(const std::string& name);
        void inputBeforeRoll(RollOfDice& rod);
        void inputAfterRoll(const RollOfDice& rod);
        void print(std::ostream& myStream) const;
        bool operator!() const ;
		int getScore() ;
};

#endif
