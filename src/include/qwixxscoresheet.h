#ifndef QWIXXCORESHEET
#define QWIXXSCORESHEET

#include "scoresheet.h"
#include <vector>


using std::vector;

class QwixxScoreSheet : public ScoreSheet {
	//holds four QwintoRow (RED, YELLOW, BLUE, GREEN)
	std::vector< QwixxRow<Class, Colour> > scoreSheetRows;

	//needs to overwrite print
};

#endif