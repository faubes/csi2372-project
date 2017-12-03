#ifndef QWIXXSCORESHEET
#define QWIXXSCORESHEET

#include "scoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;

class QwixxScoreSheet : public ScoreSheet {
	void print(std::ostream& os) const;
	int calcTotal();

	// tests whether a value can be entered into a given colour row
	bool canScoreRow(const Colour c, int val) const;

public:
	QwixxRow < std::vector<int>, Colour::RED > redRow;
	QwixxRow < std::vector<int>, Colour::YELLOW > yellowRow;
	QwixxRow < std::list<int>, Colour::GREEN > greenRow;
	QwixxRow < std::list<int>, Colour::BLUE > blueRow;

	QwixxScoreSheet(const std::string& name);
	// Checks if a combination WHITE+WHITE can be scored
	// returns vector of colours where such a score can be entered
	std::vector<Colour> getAvailableRows(const RollOfDice& rod) const;
	// Checks if a combination WHITE+NONWHITE can be scored
	std::vector<Colour> getAvailableBonusRows(const RollOfDice& rod) const;
	bool score(RollOfDice roll, Colour c);
	bool isFailedThrow(const RollOfDice& rod) const;
	bool operator!() const;
	};

#endif
