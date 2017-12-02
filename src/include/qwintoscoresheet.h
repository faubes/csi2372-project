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
        bool validateCol(RollOfDice roll, Colour c, int position);
        bool col_complete(int col);
    public:
        QwintoScoreSheet(const std::string& name);
        bool score(RollOfDice roll, Colour c, int position);
        std::vector<Colour> getAvailableRows(const RollOfDice& rod) const;
        bool isRowFull(const Colour& c) const;
        bool operator!() const;
        bool rowContains(const Colour& c, const RollOfDice & rod) const;
};

#endif
