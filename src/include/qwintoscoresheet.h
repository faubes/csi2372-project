#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET

#include "scoresheet.h"
#include <vector>

using std::vector;

class QwintoScoreSheet : public ScoreSheet {
	//holds three QwintoRow (RED, YELLOW, BLUE)
	std::vector< QwintoRow<Colour> > scoreSheetRows;

	//needs to overwrite print
};

#endif