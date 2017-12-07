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
#include <set>
#include <string>
#include <sstream>

std::vector<Colour> QwixxPlayer::availableColours(qwixxColours.begin(), qwixxColours.end());

QwixxPlayer::QwixxPlayer(const std::string& n) : Player(n), qws(n) {}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rod) {
    rod = RollOfDice(availableColours);
}

void QwixxPlayer::inputAfterRoll(const RollOfDice& rod) {

    // availableRows == 0 means activePlayer can't enter a WHITE+WHITE score
    std::vector<Colour> availableRows = this->qws.getAvailableRows(rod);

    if (isActive()) {
        // availableBonusRows == 0 means activePlayer can't enter WHITE+NONWHITE score
        std::vector<Colour> availableBonusRows = this->qws.getAvailableBonusRows(rod);

        if (availableRows.size() + availableBonusRows.size() == 0) {
            std::cout << "Too bad. You can't use this roll." << std::endl;
            this->qws.incrementFailedThrows();
            return;
        } else {
            doBonusScore(rod, availableBonusRows);
            doScore(rod, availableRows);
        }
    }
    else {
        if (!availableRows.empty()) {
            doScore(rod, availableRows);
        }
        else {
            std::cout << "Too bad. You can't use this roll." << std::endl;
            return;
        }
    }
    removeLockedDice();
}

// Helper method for processing active player's choices
void QwixxPlayer::doBonusScore(const RollOfDice& rod, std::vector<Colour> availableBonusRows) {

    bool doBonusScore = true,
         valid = false,
         validColourChosen = false,
         validWhiteChosen = false;
    RollOfDice pair;
    Colour chosen;

    while (true) {
        if (!getYesNo(std::cout, std::cin, "Do you wish to score a bonus roll?"))
            return;
        while (!validColourChosen) {
            for (const auto& d: rod ) {
                // check to see if this dice's colour is one of the available scoring rows
                bool found = std::find(availableBonusRows.begin(),
                                       availableBonusRows.end(),
                                       d.getColour())
                             != availableBonusRows.end();
                if (found) {
                    std::stringstream msg;
                    msg << "Use " << colour_to_string(d.getColour())
                        << " dice: " << static_cast<int>(d) << "?";
                    if (getYesNo(std::cout, std::cin, msg.str())) {
                        validColourChosen = true;
                        pair.addDice(d);
                        chosen = d.getColour();
                        break;
                    }
                }
            }
        }
        while (!validWhiteChosen) {
            for (int i = 2; i >= 1; i--) {
                std::stringstream msg;
                msg << "Use white dice " << (3-i) << ": " << static_cast<int>(rod[rod.size()-i]) << " ?";
                validWhiteChosen = getYesNo(std::cout, std::cin, msg.str());
                if (validWhiteChosen) {
                    pair.addDice(rod[rod.size()-i]);
                    break;
                }
            }
            if (!validWhiteChosen)
                std::cout << "You need to choose at least one of the white dice to pair with the coloured dice." <<  std::endl;
        }
        if (qws.score(pair, chosen)) {
            return;
        } else {
            std::cout << "That's now how this works." << std::endl;
            validColourChosen = false;
            validWhiteChosen = false;
        }
    }
}


void QwixxPlayer::doScore(const RollOfDice& rod, std::vector<Colour> availableRows) {

    bool doScore = true, valid = false;
    while (doScore && !valid) {
        doScore = getYesNo(std::cout, std::cin, "Do you wish to score this roll?");
        if (doScore) {
            Colour chosen;
            for (const auto& c: availableRows ) {
                std::string msg("Add score to "+ colour_to_string(c) + " row?");
                if (getYesNo(std::cout, std::cin, msg)) {
                    chosen = c;
                    break;
                }
            }
            valid = qws.score(rod.getWhitePair(), chosen);
        }
    }

}

void QwixxPlayer::print(std::ostream& os) const {
    os << this->qws;
}

int QwixxPlayer::getScore() {
    return 0;
}

bool QwixxPlayer::operator!() const {
    return !qws;
}

void QwixxPlayer::removeLockedDice() {
    std::vector<Colour> lockedRows = qws.getLockedRows();
    if (!lockedRows.empty()) {
        std::cout << "found locked rows to remove!" << std::endl;
        for (Colour c : lockedRows) {
            std::cout << "removing dice " << colour_to_string(c) <<  "since the row is now locked" << std::endl;
            auto it = std::find(availableColours.begin(), availableColours.end(), c);
			if(it != availableColours.end())
				availableColours.erase(it);
        }
    }
}
