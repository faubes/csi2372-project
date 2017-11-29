#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET

#include "scoresheet.h"
#include "qwintorow.h"
#include <vector>

using std::vector;

class QwintoScoreSheet : public ScoreSheet {
	public:
	//holds three QwintoRow (RED, YELLOW, BLUE)
	std::vector< QwintoRow <Colour> > scoreSheetRows;

	//needs to overload virtual void print(std::ostream&) const;

	//public:
		QwintoScoreSheet();
		int calcTotal();
		bool validate();
};

#endif