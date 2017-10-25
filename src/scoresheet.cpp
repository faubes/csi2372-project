
// scoresheet.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#define TEST_SCORESHEET
#include "scoresheet.h"
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::sort;

// tally of created scoresheets
int Scoresheet::count = 0;

// default constructor
Scoresheet::Scoresheet() :
	Scoresheet(string("Player ") + std::to_string(Scoresheet::count + 1))
{ };

// constructor with custom name
Scoresheet::Scoresheet(std::string str) :
	player_name(str) {
	Scoresheet::count++;
	//initialized the blocked out array values
	scoresheet_array[0][0] = -2;
	scoresheet_array[0][1] = -2;
	scoresheet_array[0][5] = -1;
	scoresheet_array[1][0] = -2;
	scoresheet_array[1][6] = -1;
	scoresheet_array[1][11] = -2;
	scoresheet_array[2][4] = -1;
	scoresheet_array[2][10] = -2;
	scoresheet_array[2][11] = -2;

	for (int i = 0; i < 12; i++) {
		scoresheet_array[3][i] = -1;
	}

	//testing
	scoresheet_array[0][2] = 2;
	scoresheet_array[0][3] = 3;
	scoresheet_array[0][4] = 6;
	scoresheet_array[0][6] = 9;
	scoresheet_array[0][7] = 11;
	scoresheet_array[0][8] = 12;
	scoresheet_array[0][9] = 13;
	scoresheet_array[0][10] = 15;
	scoresheet_array[0][11] = 16;
	scoresheet_array[1][1] = 1;
	scoresheet_array[1][2] = 3;
	scoresheet_array[1][3] = 4;
	scoresheet_array[1][4] = 5;
	scoresheet_array[1][7] = 12;
	scoresheet_array[1][8] = 13;
	scoresheet_array[2][0] = 1;
	scoresheet_array[2][1] = 3;
	scoresheet_array[2][3] = 6;
	scoresheet_array[2][5] = 7;
	scoresheet_array[2][8] = 10;

	penalties = 3;
}

void Scoresheet::print(std::ostream& myStream)
{
	std::string builder;

	builder += "Player name: " + this->player_name + "\n" + "Card count: " + std::to_string(this->count) + "\n";

	//row 0 R
	builder += Scoresheet::get_ascii_colour(Scoresheet::colour::RED);
	builder += "               -------------------------------\nRed:     ";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[0][i] == -2) {
			if (i == 1) {
				builder += "   |";
			}

			else {
				builder += "   ";
			}
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[0][i] == -1) {
			builder += "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[0][i] < 10) {
				builder += " " + std::to_string(this->scoresheet_array[0][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder += std::to_string(this->scoresheet_array[0][i]);
			}

			if (i == 2 || i == 3 || i == 6 || i == 7) {
				builder += "%";
			}

			else {
				builder += "|";
			}
		}
	}

	builder += "\n";

	//row 1 B
	builder += Scoresheet::get_ascii_colour(Scoresheet::colour::BLUE);
	builder += "            ----------------------------------\nBlue:    ";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[1][i] == -2) {
			if (i == 0) {
				builder += "   |";
			}

			else {
				builder += "   ";
			}
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[1][i] == -1) {
			builder += "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[1][i] < 10) {
				builder += " " + std::to_string(this->scoresheet_array[1][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder += std::to_string(this->scoresheet_array[1][i]);
			}

			if (i == 7 || i == 8) {
				builder += "%";
			}

			else {
				builder += "|";
			}
		}
	}

	builder += "\n";

	//row 3 Y
	builder += Scoresheet::get_ascii_colour(Scoresheet::colour::YELLOW);
	builder += "         ----------------------------------   \nYellow:  |";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[2][i] == -2) {
			builder += "   ";
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[2][i] == -1) {
			builder += "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[2][i] < 10) {
				builder += " " + std::to_string(this->scoresheet_array[2][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder += std::to_string(this->scoresheet_array[2][i]);
			}

			if (i == 1 || i == 2 || i == 8 || i == 9) {
				builder += "%";
			}

			else {
				builder += "|";
			}
		}
	}

	// reset to white/black
	builder += "\033[0m";

	//we handle the failed throws print here (i.e. row 3)

	builder += "\nFailed throws: ";

	for (int i = 0; i < 12; i++) {
		if (this->penalties != 0) {
			if (this->scoresheet_array[3][i] != -1) {
				builder += std::to_string(this->scoresheet_array[3][i]) + " ";
			}
		}
	}

	myStream << builder << std::endl;
}

// validate cell 
const bool Scoresheet::validate_cell(const int &row, const int &col) {
	// only 0 entries are safe to score
	// negatives are out of bounds, positives already contain a score
	return this->scoresheet_array[row][col] == 0;
}


// validate column is unique
const bool Scoresheet::validate_col(const int &col) {
	bool valid = true;
	std::vector<int> values;

	// filter out zeroes and negatives
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][col] > 0) {
			values.emplace_back(this->scoresheet_array[i][col]);
		}
	}
	// sort copied values so we can compare only neighbours for uniqueness
	sort(values.begin(), values.end());

	for (int j = 0; j < values.size(); j++) {
		if (values[j] == values[j + 1]) {
			valid = false;
		}

	}
	return valid;
}

// validate row is ascending
const bool Scoresheet::validate_row(const int &row) {
	bool valid = true;
	std::vector<int> values;
	// filter out zeroes and negatives
	for (int i = 0; i < 12; i++) {
		if (this->scoresheet_array[row][i] > 0) {
			values.emplace_back(this->scoresheet_array[row][i]);
		}
	}
	// create copy of values
	std::vector<int> original(values);
	// sort values
	sort(values.begin(), values.end());

	// check if original == sorted
	return original == values;

}

void Scoresheet::score(const int roll, const int row, const int col) {
	if (!this->validate_cell(row, col)) throw("Invalid cell");
	Scoresheet tmp = *this;
	tmp.scoresheet_array[row][col] = roll;
	if (!tmp.validate_col(col)) throw("Invalid score: column elements not distinct.");
	if (!tmp.validate_row(row)) throw ("Invalid score: row not ascending.");
	*this = tmp; // copy constructor replaces old scoresheet with valid new scoresheet
}


int Scoresheet::calculate_score() {
	int score = 0;
	bool rFlag = true;
	int rcount = 0;
	bool bFlag = true;
	int bcount = 0;
	bool yFlag = true;
	int ycount = 0;
	bool b2Flag = true;
	bool b3Flag = true;
	bool b7Flag = true;
	bool b8Flag = true;
	bool b9Flag = true;

	//check if R is filled
	for (int i = 0; i < 12; i++) {
		if (this->scoresheet_array[0][i] == 0) {
			// then it's not filled
			rFlag = false;
		}

		else {
			if (this->scoresheet_array[0][i] > 0) {
				rcount++;
			}
		}
	}

	if (rFlag == true) {
		score += this->scoresheet_array[0][11];
	}

	else {
		score += rcount;
	}

	//std::cout << score << std::endl;

	//check if B is filled
	for (int i = 0; i < 12; i++) {
		if (this->scoresheet_array[1][i] == 0) {
			// then it's not filled
			bFlag = false;
		}

		else {
			if (this->scoresheet_array[1][i] > 0) {
				bcount++;
			}
		}
	}

	if (bFlag == true) {
		score += this->scoresheet_array[1][10];
	}

	else {
		score += bcount;
	}

	//std::cout << score << std::endl;

	//check if Y is filled
	for (int i = 0; i < 12; i++) {
		if (this->scoresheet_array[2][i] == 0) {
			// then it's not filled
			yFlag = false;
		}

		else {
			if (this->scoresheet_array[2][i] > 0) {
				ycount++;
			}
		}
	}

	if (yFlag == true) {
		score += this->scoresheet_array[2][9];
	}

	else {
		score += ycount;
	}

	//std::cout << score << std::endl;

	//check if columns 2, 3, 7, 8, 9 are filled for bonus

	//column 2
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][2] == 0) {
			b2Flag = false;
		}
	}

	if (b2Flag == true) {
		score += this->scoresheet_array[2][2];
	}

	//column 3
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][3] == 0) {
			b3Flag = false;
		}
	}

	if (b3Flag == true) {
		score += this->scoresheet_array[0][3];
	}

	//column 7
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][7] == 0) {
			b7Flag = false;
		}
	}

	if (b7Flag == true) {
		score += this->scoresheet_array[0][7];
	}

	//column 8
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][8] == 0) {
			b8Flag = false;
		}
	}

	if (b8Flag == true) {
		score += this->scoresheet_array[1][8];
	}

	//column 9
	for (int i = 0; i < 3; i++) {
		if (this->scoresheet_array[i][9] == 0) {
			b9Flag = false;
		}
	}

	if (b9Flag == true) {
		score += this->scoresheet_array[2][9];
	}

	score = score - (5 * this->penalties);

	return score;
}

#ifdef TEST_SCORESHEET

int main(int argc, char **argz) {
	std::cout << "Test Scoresheet" << std::endl;

	Scoresheet myScoresheet = Scoresheet();
	myScoresheet.print(cout);

	try {
		myScoresheet.score(1, 0, 3);
		myScoresheet.print(cout);

		myScoresheet.score(5, 0, 2);
		myScoresheet.print(cout);
	}
	catch (const char * err) {
		cout << err << endl;
	}

	std::cout << "Score: " << myScoresheet.calculate_score() << std::endl;

	//remove this eventually, for my own testing in Visual Studio because it's stupid
	//system("PAUSE");

	return 0;
}

#endif
