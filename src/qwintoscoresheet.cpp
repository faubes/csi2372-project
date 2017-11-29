#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet() {}

int QwintoScoreSheet::calcTotal() {
	return 0;
}

bool QwintoScoreSheet::validate() {
	return false;
}

std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qss) {
	std::stringstream output;
	output << qss.redRow;
	output << qss.yellowRow;
	output << qss.blueRow;
	os << output.str(); 
	return os;
}
