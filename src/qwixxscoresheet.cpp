// qwixxscoresheet.cpp

#include "qwixxscoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;


QwixxScoreSheet::QwixxScoreSheet(const std::string& name) : ScoreSheet(name) {}

void QwixxScoreSheet::print(std::ostream& myStream) const {}
int QwixxScoreSheet::calcTotal() {
    return 0;
}
bool QwixxScoreSheet::score(RollOfDice roll, Colour c, int position) {
    return false;
}

bool QwixxScoreSheet::isFailedThrow(const RollOfDice& rod) const {
    return false;
}
bool QwixxScoreSheet::operator! () const {
    return false;
}
