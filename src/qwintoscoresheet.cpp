#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet() {
	QwintoRow<Colour> myRed(Colour::RED);
	QwintoRow<Colour> myYellow(Colour::YELLOW);
	QwintoRow<Colour> myBlue(Colour::BLUE);

	scoreSheetRows.push_back(myRed);
	scoreSheetRows.push_back(myYellow);
	scoreSheetRows.push_back(myBlue);
	/*std::cout << scoreSheetRows[0].getValueAtindex(0) << std::endl;
	std::cout << scoreSheetRows[1].getValueAtindex(0) << std::endl;
	std::cout << scoreSheetRows[2].getValueAtindex(0) << std::endl;*/
}

int QwintoScoreSheet::calcTotal() {
	return 0;
}

bool QwintoScoreSheet::validate() {
	return false;
}