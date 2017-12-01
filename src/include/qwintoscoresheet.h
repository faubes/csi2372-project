#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET

#include "scoresheet.h"
#include "qwintorow.h"
#include <vector>

using std::vector;

class QwintoScoreSheet : public ScoreSheet {
		QwintoRow<Colour::RED> redRow;
		QwintoRow<Colour::YELLOW> yellowRow;
		QwintoRow<Colour::BLUE> blueRow;

		void print(std::ostream& myStream) const;
		int calcTotal();
		// The function score is to call the protected pure virtual function validate internally.
		bool validate(RollOfDice roll, Colour c, int position);
		bool operator!() const;
		bool col_complete();
	public:
		QwintoScoreSheet();
		bool score(RollOfDice roll, Colour c, int position);
};

#endif
