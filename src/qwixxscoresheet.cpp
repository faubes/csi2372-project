// qwixxscoresheet.cpp

#include "qwixxscoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;

class QwixxScoreSheet : public ScoreSheet {
	QwixxRow < std::vector<int>, Colour::RED > redRow;
	QwixxRow < std::vector<int>, Colour::YELLOW > yellowRow;
	QwixxRow < std::list<int>, Colour::GREEN > greenRow;
	QwixxRow < std::list<int>, Colour::BLUE > blueRow;

	void print(std::ostream& myStream) const;
	int calcTotal();

	public:
		QwixxScoreSheet(const std::string& name);
		bool score(RollOfDice roll, Colour c, int position);
		bool isFailedThrow(const RollOfDice& rod) const;
};
