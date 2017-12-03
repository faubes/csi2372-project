#ifndef QWIXXSCORESHEET
#define QWIXXSCORESHEET

#include "scoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;

class QwixxScoreSheet : public ScoreSheet {
	void print(std::ostream& myStream) const;
	int calcTotal();

public:
	QwixxRow < std::vector<int>, Colour::RED > redRow;
	QwixxRow < std::vector<int>, Colour::YELLOW > yellowRow;
	QwixxRow < std::list<int>, Colour::GREEN > greenRow;
	QwixxRow < std::list<int>, Colour::BLUE > blueRow;

	QwixxScoreSheet(const std::string& name);
	bool score(RollOfDice roll, Colour c, int position);
	bool isFailedThrow(const RollOfDice& rod) const;
	bool operator!() const;
};

#endif
