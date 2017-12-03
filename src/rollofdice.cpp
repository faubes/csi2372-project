// rollofdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/


#include "rollofdice.h"
#include <algorithm>

RollOfDice::RollOfDice() :
    rod(std::vector<Dice>()) {}

RollOfDice::RollOfDice(const std::vector<Colour>& colours) :
    rod(std::vector<Dice>()) {
    for (const Colour& c : colours) {
        rod.emplace_back(Dice(c));
    }
}


void RollOfDice::addDice(const Dice& d) {
    rod.emplace_back(Dice(d));
}

RollOfDice RollOfDice::getPair(int i, int j) const
{
    RollOfDice pairOfDice;
    pairOfDice.addDice((*this)[i]);
    pairOfDice.addDice((*this)[j]);
    return pairOfDice;
}

RollOfDice RollOfDice::getWhitePair() const
{
    RollOfDice pairOfDice;
    pairOfDice.addDice((*this)[(*this).size() -1]);
    pairOfDice.addDice((*this)[(*this).size() -2]);
    return pairOfDice;
}

void RollOfDice::roll() {
    for (auto& d : rod) {
        d.roll();
    }
}

RollOfDice::operator int() const {
    int total = 0;
    for (auto &d : rod) {
        total += d.getValue();
    }
    return total;
}

std::ostream& operator<<(std::ostream& os, const RollOfDice& rod) {
    for (const auto& d : rod) {
        os << colour_to_string(d.getColour());
        os << ": ";
        os << d;
        os << " ";
    }
    os << std::endl;
    os << "Total: " << static_cast<int>(rod) << std::endl;
    return os;
}
