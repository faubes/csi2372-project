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
		
		//needs to overload virtual void print(std::ostream&) const;
		friend std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qss);

	public:
		QwintoScoreSheet();
		int calcTotal();
		bool validate();
};

#endif
