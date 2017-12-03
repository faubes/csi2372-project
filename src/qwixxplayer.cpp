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
#include <sstream>

std::vector<Colour> QwixxPlayer::availableColours = qwixxColours;

QwixxPlayer::QwixxPlayer(const std::string& n) : Player(n), qws(n) {}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rod) {
    rod = RollOfDice(availableColours);
}

void QwixxPlayer::inputAfterRoll(const RollOfDice& rod) {

    if (isActive()) {
        inputAfterRollActive(rod);
    }
    else {
        inputAfterRollInactive(rod);
    }
}

// Helper method for processing active player's choices
void QwixxPlayer::inputAfterRollActive(const RollOfDice& rod) {
    // availableRows == 0 means activePlayer can't enter a WHITE+WHITE score
    std::vector<Colour> availableRows = this->qws.getAvailableRows(rod);
    // availableBonusRows == 0 means activePlayer can't enter WHITE+NONWHITE score
    std::vector<Colour> availableBonusRows = this->qws.getAvailableBonusRows(rod);

    if (availableRows.size() + availableBonusRows.size() == 0) {
        std::cout << "Too bad. You can't use this roll." << std::endl;
        this->qws.incrementFailedThrows();
        return;
    }

    bool doBonusScore = true, 
		valid = false, 
		validColourChosen = false, 
		validWhiteChosen = false;

    RollOfDice pair;
    Colour chosen;
    
    while (doBonusScore && !valid) {
        doBonusScore = getYesNo(std::cout, std::cin, "Do you wish to score a bonus roll?");
        if (doBonusScore) {

            for (const auto& d: rod ) {
                // if this dice's colour is one of the available scoring rows
                bool found = std::find(availableBonusRows.begin(),
                                       availableBonusRows.end(),
                                       d.getColour())
                             != availableBonusRows.end();
                if (found) {
                    std::stringstream msg;
                    msg << "Use " << colour_to_string(d.getColour()) << " dice: " << static_cast<int>(d) << "?";
                    if (getYesNo(std::cout, std::cin, msg.str())) {
                        validColourChosen = true;
                        pair.addDice(d);
                        chosen = d.getColour();
                        break;
                    }
                }
            }
            while (!validWhiteChosen) {
				std::stringstream msg;
				msg << "Use first white dice: " << static_cast<int>(rod[rod.size()-2]) << " ?";
                validWhiteChosen =
                    getYesNo(std::cout, std::cin, msg.str());
                if (!validWhiteChosen) {
					msg.clear();
					msg <<"Use second white dice: " << static_cast<int>(rod[rod.size()-1]) << " ?";
                    validWhiteChosen =
                        getYesNo(std::cout, std::cin, msg.str());
                }
                if (!validWhiteChosen) {
                    std::cout << "You need to choose at least one of the white dice to pair with the coloured dice." <<  std::endl;
                }
            }
            if (validWhiteChosen && validColourChosen)
                valid = true;
            if (!valid)
                std::cout << "Hmm, invalid selection of dice." << std::endl;
        }
        qws.score(pair, chosen);

    }
}

void QwixxPlayer::inputAfterRollInactive(const RollOfDice& rod) {

    // availableRows == 0 means inactivePlayer can't enter a WHITE+WHITE score
    std::vector<Colour> availableRows = this->qws.getAvailableRows(rod);
    if (availableRows.size() == 0) {
        std::cout << "Too bad. You can't use this roll." << std::endl;
        return;
    }
    bool doScore = true, valid = false;
    while (doScore && !valid) {
        doScore = getYesNo(std::cout, std::cin, "Do you wish to score this roll?");
        if (doScore) {
            Colour chosen;
            for (const auto& c: availableRows ) {
                std::string msg("Add score to "+ colour_to_string(c) + " row?");
                if (getYesNo(std::cout, std::cin, msg)) {
                    valid = true;
                    chosen = c;
                    break;
                }
            }
            qws.score(rod.getWhitePair(), chosen);
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
    return false;
}
