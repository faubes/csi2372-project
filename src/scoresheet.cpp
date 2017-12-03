#include "scoresheet.h"

//Base class
//The class ScoreSheet is the abstract parent class for the two different score sheets in Qwixx and Qwinto.

ScoreSheet::ScoreSheet(const std::string& n) : name(n) {}

void ScoreSheet::print(std::ostream& myStream) const {
    //do nothing
}

bool ScoreSheet::operator!() const {
    return false;
}

bool ScoreSheet::score(RollOfDice roll, Colour c, int position) {
    std::cout << "Score from ScoreSheet and no children" << std::endl;
    return false;
}
