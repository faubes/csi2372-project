#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet(const std::string& n) : ScoreSheet(n) {}

bool QwintoScoreSheet::col_complete(int col) {
	return ((redRow[col] != 0) && (yellowRow[col] != 0) && (blueRow[col] != 0));
}

int QwintoScoreSheet::calcTotal() {
	int newScore = 0;
	
	//filled row stuff
	if (redRow.row_complete() == 9) {
		//get most right
		newScore += redRow[11];
		std::cout << redRow[11] << std::endl;
	}

	else {
		//return the count itself
		newScore += redRow.row_complete();
		std::cout << redRow.row_complete() << std::endl;
	}

	if(yellowRow.row_complete() == 9) {
		//get most right
		newScore += yellowRow[10];
		std::cout << yellowRow[10] << std::endl;
	}

	else {
		//return the count itself
		newScore += yellowRow.row_complete();
		std::cout << yellowRow.row_complete() << std::endl;
	}

	if (blueRow.row_complete() == 9) {
		//get most right
		newScore += blueRow[9];
		std::cout << blueRow[9] << std::endl;
	}

	else {
		//return the count itself
		newScore += blueRow.row_complete();
		std::cout << blueRow.row_complete() << std::endl;
	}

	//bonus points (the % cells)
	//col 2
	if (col_complete(2)) {
		newScore += blueRow[2];
		std::cout << blueRow[2] << std::endl;
	}
	//col 3
	if (col_complete(3)) {
		newScore += redRow[3];
		std::cout << redRow[3] << std::endl;
	}
	//col 7
	if (col_complete(7)) {
		newScore += redRow[7];
		std::cout << redRow[7] << std::endl;
	}
	//col 8
	if (col_complete(8)) {
		newScore += yellowRow[8];
		std::cout << yellowRow[8] << std::endl;
	}
	//col 9
	if (col_complete(9)) {
		newScore += blueRow[9];
		std::cout << blueRow[9] << std::endl;
	}

	//failed throws
	newScore = newScore - (5 * getFailedThrows());

	return newScore;
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
	bool valid_row;
	bool valid_col;
	int row;
	
	if (colour_to_string(c) == "Red") {
		valid_row = redRow.validate(roll, position);
		row = 0;
	}

	else if (colour_to_string(c) == "Yellow") {
		valid_row = yellowRow.validate(roll, position);
		row = 1;
	}

	else if (colour_to_string(c) == "Blue") {
		valid_row = blueRow.validate(roll, position);
		row = 2;
	}

	else {
		std::cout << "Error" << std::endl;
	}

	//std::cout << row << std::endl;

	//std::cout << "row check " << valid_row << std::endl;

	//this is column check
	valid_col = validate(roll, c, position);

	//std::cout << "column check " << valid_col << std::endl;


	if ((valid_row == true) && (valid_col == true)) {
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

	return ((valid_row == true) && (valid_col == true));
}

// Lazy way to test if there is a valid place to enter a score
// creates a copy of scoresheet and tests all possible locations
// until a valid one is found
bool QwintoScoreSheet::isFailedThrow(const RollOfDice& rod) const {
	bool valid = false;
	QwintoScoreSheet copy(*this);
	for (const auto& d : rod) {
		for (int i = 0; i < 12; i++) {
			valid = copy.score(rod, d.getColour(), i);
			if (valid) break;
		}
		if (valid) break;
	}
	return !valid;
}

bool QwintoScoreSheet::isRowFull(const Colour& c) const {
	switch(c) {
		case(Colour::RED):
			return this->redRow.isFull();
			break;
		case(Colour::YELLOW):
			return this->yellowRow.isFull();
			break;
		case(Colour::BLUE):
			return this->blueRow.isFull();
			break;	
	}
}
