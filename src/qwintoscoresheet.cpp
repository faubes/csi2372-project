#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet(const std::string& n) : ScoreSheet(n) {}

int QwintoScoreSheet::calcTotal() {
	return 0;
}

bool QwintoScoreSheet::validate(RollOfDice roll, Colour c, int position) {
	bool valid = true;
	std::vector<int> values;

	if (colour_to_string(c) == "Red") {
		// filter out zeroes and negatives
		values.emplace_back(static_cast<int>(roll));

		if (yellowRow[position] > 0) {
			values.emplace_back(yellowRow[position]);
		}

		if (blueRow[position] > 0) {
			values.emplace_back(blueRow[position]);
		}
	}

	else if (colour_to_string(c) == "Yellow") {
		// filter out zeroes and negatives
		if (redRow[position] > 0) {
			values.emplace_back(redRow[position]);
		}

		values.emplace_back(static_cast<int>(roll));

		if (blueRow[position] > 0) {
			values.emplace_back(blueRow[position]);
		}
	}

	else if (colour_to_string(c) == "Blue") {
		// filter out zeroes and negatives
		if (redRow[position] > 0) {
			values.emplace_back(redRow[position]);
		}

		if (yellowRow[position] > 0) {
			values.emplace_back(yellowRow[position]);
		}

		values.emplace_back(static_cast<int>(roll));
	}

	else {
		std::cout << "Error" << std::endl;
	}

	// sort copied values so we can compare only neighbours for uniqueness
	sort(values.begin(), values.end());

	for (int j = 0; j < values.size() - 1; j++) {
		if (values[j] == values[j + 1]) {
			valid = false;
		}

	}
	return valid;
}

void QwintoScoreSheet::print(std::ostream& os) const {
	std::stringstream output;
	output << redRow;
	output << yellowRow;
	output << blueRow;
	os << output.str(); 
}

bool QwintoScoreSheet::operator!() const {
	return false;
}

bool QwintoScoreSheet::score(RollOfDice roll, Colour c, int position) {
	//call the QwintoRow validate to check if a) the cell is valid b) the new value is valid in a row context
	bool valid = false;
	int row;
	
	if (colour_to_string(c) == "Red") {
		valid = redRow.validate(roll, position);
		row = 0;
	}

	else if (colour_to_string(c) == "Yellow") {
		valid = yellowRow.validate(roll, position);
		row = 1;
	}

	else if (colour_to_string(c) == "Blue") {
		valid = blueRow.validate(roll, position);
		row = 2;
	}

	else {
		std::cout << "Error" << std::endl;
	}

	//std::cout << row << std::endl;

	//std::cout << "row check " << valid << std::endl;

	//this is column check
	valid = validate(roll, c, position);

	//std::cout << "column check " << valid << std::endl;

	if (valid == true) {
		//then we make insertion
		if (row == 0) {
			//Red
			redRow[position] = roll;
		}

		else if (row == 1) {
			//Yellow
			yellowRow[position] = roll;
		}

		else if (row == 2) {
			//Blue
			blueRow[position] = roll;
		}

		else {
			std::cout << "Error" << std::endl;
		}
	}

	return valid;
}
