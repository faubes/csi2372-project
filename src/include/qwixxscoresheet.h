#ifndef QWIXXCORESHEET
#define QWIXXSCORESHEET

#include "scoresheet.h"
#include "qwixxrow.h"
#include <vector>
#include <list>

using std::vector;
using std::list;

class QwixxScoreSheet : public ScoreSheet {
        //holds four QwixxRow (RED, YELLOW, BLUE, GREEN)
        QwixxRow<std::vector, int, Colour> scoreSheetRowRed;
        QwixxRow<std::vector, int, Colour> scoreSheetRowYellow;
        QwixxRow<std::list, int, Colour> scoreSheetRowGreen;
        QwixxRow<std::list, int, Colour> scoreSheetRowBlue;

        //needs to overwrite print
};

#endif
