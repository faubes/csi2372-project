#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet() {}

int QwintoScoreSheet::calcTotal() {
	return 0;
}

bool QwintoScoreSheet::validate() {
	return false;
}

void QwintoScoreSheet::print(std::ostream& os) const {
	std::stringstream output;
	output << redRow;
	output << yellowRow;
	output << blueRow;
	os << output.str(); 
}
