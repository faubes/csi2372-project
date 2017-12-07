// qwixxscoresheet.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#include "qwixxscoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;

QwixxScoreSheet::QwixxScoreSheet(const std::string& name) :
    ScoreSheet(name), redRow{}, yellowRow{}, greenRow{}, blueRow{} {
    for (int i = 2; i <= 12; i++) {
        redRow.add(i);
        yellowRow.add(i);
        greenRow.add(14-i);
        blueRow.add(14-i);
    }

    //the below is the test example in the project specifications!
    /*incrementFailedThrows();
    incrementFailedThrows();

    redRow.add(2);
    redRow.add(3);
    redRow.add(4);
    redRow.add(5);
    redRow.add(6);
    redRow.add(7);
    redRow.add(8);
    redRow.add(0);
    redRow.add(0);
    redRow.add(11);
    redRow.add(0);

    redRow.setCounter(3);

    yellowRow.add(2);
    yellowRow.add(0);
    yellowRow.add(4);
    yellowRow.add(5);
    yellowRow.add(0);
    yellowRow.add(0);
    yellowRow.add(8);
    yellowRow.add(9);
    yellowRow.add(10);
    yellowRow.add(11);
    yellowRow.add(12);

    yellowRow.setCounter(3);

    greenRow.add(12);
    greenRow.add(11);
    greenRow.add(10);
    greenRow.add(0);
    greenRow.add(8);
    greenRow.add(0);
    greenRow.add(6);
    greenRow.add(0);
    greenRow.add(0);
    greenRow.add(3);
    greenRow.add(0);

    greenRow.locked = true;
    greenRow.setCounter(5);

    blueRow.add(12);
    blueRow.add(0);
    blueRow.add(10);
    blueRow.add(9);
    blueRow.add(8);
    blueRow.add(7);
    blueRow.add(6);
    blueRow.add(0);
    blueRow.add(4);
    blueRow.add(3);
    blueRow.add(2);

    blueRow.setCounter(2);*/
}

int QwixxScoreSheet::calcTotal() {
    int score = 0;
    int redCounterBonus = 0;
    int yellowCounterBonus = 0;
    int greenCounterBonus = 0;
    int blueCounterBonus = 0;

    //get the "count" of cells filled in with +1 bonus for locked
    if (redRow.getLocked() == true) {
        redCounterBonus = redRow.getCounter() + 1;
    }

    else {
        redCounterBonus = redRow.getCounter();
    }

    if (yellowRow.getLocked() == true) {
        yellowCounterBonus = yellowRow.getCounter() + 1;
    }

    else {
        yellowCounterBonus = yellowRow.getCounter();
    }

    if (greenRow.getLocked() == true) {
        greenCounterBonus = greenRow.getCounter() + 1;
    }

    else {
        greenCounterBonus = greenRow.getCounter();
    }

    if (blueRow.getLocked() == true) {
        blueCounterBonus = blueRow.getCounter() + 1;
    }

    else {
        blueCounterBonus = blueRow.getCounter();
    }

    //filled entries stuff
    score += scoreForEntriesFilled(redCounterBonus);
    //std::cout << score << std::endl;
    score += scoreForEntriesFilled(yellowCounterBonus);
    //std::cout << score << std::endl;
    score += scoreForEntriesFilled(greenCounterBonus);
    //std::cout << score << std::endl;
    score += scoreForEntriesFilled(blueCounterBonus);
    //std::cout << score << std::endl;

    //calculating penalties
    score = score - getFailedThrows()*5;

    return score;
}

int QwixxScoreSheet::scoreForEntriesFilled(int i) {
    if (i == 1) {
        return 1;
    }

    else if (i == 2) {
        return 3;
    }

    else if (i == 3) {
        return 6;
    }

    else if (i == 4) {
        return 10;
    }

    else if (i == 5) {
        return 15;
    }

    else if (i == 6) {
        return 21;
    }

    else if (i == 7) {
        return 28;
    }

    else if (i == 8) {
        return 36;
    }

    else if (i == 9) {
        return 45;
    }

    else if (i == 10) {
        return 55;
    }

    else if (i == 11) {
        return 66;
    }

    else if (i == 12) {
        return 78;
    }

    else {
        return -1;
    }
}

bool QwixxScoreSheet::score(RollOfDice rod, Colour c) {
    bool valid = false;
    try {
        switch(c) {
        case(Colour::RED):
            redRow += rod;
            valid = true;
            break;
        case(Colour::YELLOW):
            yellowRow += rod;
            valid = true;
            break;
        case(Colour::BLUE):
            blueRow += rod;
            valid = true;
            break;
        case(Colour::GREEN):
            greenRow += rod;
            valid = true;
            break;
        default:
            std::cout << "Error?" << std::endl;
            valid = false;
            break;
        }
    }
    catch (std::string s) {
        valid = false;
        std::cout << s << std::endl;

    }
    return valid;
}

bool QwixxScoreSheet::isFailedThrow(const RollOfDice& rod) const {
    return false;
}
bool QwixxScoreSheet::operator! () const {
    int lockCount = 0;
    if (redRow.getLocked()) lockCount++;
    if (yellowRow.getLocked()) lockCount++;
    if (blueRow.getLocked()) lockCount++;
    if (greenRow.getLocked()) lockCount++;
    return ((getFailedThrows() >3) || (lockCount > 1));
}

void QwixxScoreSheet::print(std::ostream& os) const {
    std::stringstream output;
    output << redRow;
    output << yellowRow;
    output << greenRow;
    output << blueRow;
    os << output.str();
    os << "Failed throws: " << getFailedThrows() << std::endl;
}

// helper method to check if it's possible to score val in row c
bool QwixxScoreSheet::canScoreRow(const Colour c, int val) const {
    bool valid = false;
    switch (c) {
    case(Colour::RED):
        valid = (!redRow.getLocked()) && (val > redRow.getLast());
        break;
    case(Colour::BLUE):
        valid = (!blueRow.getLocked()) && (val > blueRow.getLast());
        break;
    case(Colour::GREEN):
        return (!greenRow.getLocked()) && (val > greenRow.getLast());
        break;
    case(Colour::YELLOW):
        return (!yellowRow.getLocked()) && (val > yellowRow.getLast());
        break;
    default:
        std::cerr << "Uh oh. Broken canScoreRow method" << std::endl;
        break;
    }
    return valid;
}

std::vector<Colour> QwixxScoreSheet::getAvailableBonusRows(const RollOfDice& rod) const {
    std::vector<Colour> res;
    Dice w1 = rod[rod.size()-2];
    Dice w2 = rod[rod.size()-1];

    // test all possible pairs WHITE+NONWHITE for scorable sum
    // as well as checking if WHITE+WHITE is valid
    for (const auto& d : rod) {
        if (d.getColour() != Colour::WHITE) {
            if (canScoreRow(d.getColour(), d + w1) ||
                    canScoreRow(d.getColour(), d + w2)) {
                res.emplace_back(d.getColour());
            }
        }
    }
    return res;
}
std::vector<Colour> QwixxScoreSheet::getAvailableRows(const RollOfDice& rod) const {
    std::vector<Colour> res;
    Dice w1 = rod[rod.size()-2];
    Dice w2 = rod[rod.size()-1];

    // test all possible pairs WHITE+NONWHITE for scorable sum
    // as well as checking if WHITE+WHITE is valid
    for (const auto& d : rod) {
        if (d.getColour() != Colour::WHITE) {
            if (canScoreRow(d.getColour(), w1 + w2)) {
                res.emplace_back(d.getColour());
            }
        }
    }
    return res;
}

std::vector<Colour> QwixxScoreSheet::getLockedRows() const {
    std::vector<Colour> lockedRows;
    if (redRow.getLocked()) {
        lockedRows.emplace_back(Colour::RED);
    }
    if (blueRow.getLocked()) {
        lockedRows.emplace_back(Colour::BLUE);
    }
    if (yellowRow.getLocked()) {
        lockedRows.emplace_back(Colour::YELLOW);
    }
    if (greenRow.getLocked()) {
        lockedRows.emplace_back(Colour::GREEN);
    }
    return lockedRows;
}
