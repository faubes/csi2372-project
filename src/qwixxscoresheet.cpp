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
bool QwixxScoreSheet::score(RollOfDice roll, Colour c, int position) {
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
