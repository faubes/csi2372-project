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

	public:
		void print(std::ostream& myStream) const;
		QwintoScoreSheet();
		int calcTotal();
		bool validate();
};

#endif
