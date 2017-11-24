#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET

#include "scoresheet.h"
#include "qwintorow.h"
#include <vector>

using std::vector;

class QwintoScoreSheet : public ScoreSheet {
	//holds three QwintoRow (RED, YELLOW, BLUE)
	std::vector< QwintoRow <Colour> > scoreSheetRows;

	//needs to overwrite insertion operator for printing
};

#endif