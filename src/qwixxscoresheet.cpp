// qwixxscoresheet.cpp

#include "qwixxscoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;


QwixxScoreSheet::QwixxScoreSheet(const std::string& name) :
    ScoreSheet(name), redRow{}, yellowRow{}, greenRow{}, blueRow{} {
    for (int i =2; i <= 12; i++) {
        redRow.add(i);
        yellowRow.add(i);
        greenRow.add(14-i);
        blueRow.add(14-i);
    }
}

int QwixxScoreSheet::calcTotal() {
    return 0;
}
bool QwixxScoreSheet::score(RollOfDice roll, Colour c) {
    return false;
}

bool QwixxScoreSheet::isFailedThrow(const RollOfDice& rod) const {
    return false;
}
bool QwixxScoreSheet::operator! () const {
    return false;
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
        valid = (!redRow) && (val > redRow.getLast());
        break;
    case(Colour::BLUE):
        valid = (!blueRow) && (val > blueRow.getLast());
        break;
    case(Colour::GREEN):
        return (!greenRow) && (val > greenRow.getLast());
        break;
    case(Colour::YELLOW):
        return (!yellowRow) && (val > yellowRow.getLast());
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
