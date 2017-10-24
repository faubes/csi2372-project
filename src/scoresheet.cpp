// scoresheet.h
/* 
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/
#define TEST_SCORESHEET
#include "scoresheet.h"
using std::cout;

int Scoresheet::cardcount = 0;

SScoresheet::Scoresheet() :
	Scoresheet("Player")// + (++Scoresheet::cardcount)) //commented out because code needs to be revisited
{
	//Scoresheet::cardcount++;
};

Scoresheet::Scoresheet(std::string str) :
	player_name(str) {
	Scoresheet::cardcount++;
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

	//testing
	scoresheet_array[0][4] = 10;
}

void Scoresheet::print(std::ostream& myStream)
{	
	std::string builder;

	builder = builder + "Player name: " + this->player_name + "\n" + "Card count: " + std::to_string(this->cardcount) + "\n";

	//row 0 R
	builder = builder + "               -------------------------------\nRed:     ";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[0][i] == -2) {
			if (i == 1) {
				builder = builder + "   |";
			}

			else {
				builder = builder + "   ";
			}
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[0][i] == -1) {
			builder = builder + "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[0][i] < 10) {
				builder = builder + " " + std::to_string(this->scoresheet_array[0][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder = builder + std::to_string(this->scoresheet_array[0][i]);
			}

			if (i == 3 || i == 4 || i == 7 || i == 8) {
				builder = builder + "%";
			}

			else {
				builder = builder + "|";
			}
		}
	}

	builder = builder + "\n";

	//row 1 B
	builder = builder + "            ----------------------------------\nBlue:    ";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[1][i] == -2) {
			if (i == 0) {
				builder = builder + "   |";
			}

			else {
				builder = builder + "   ";
			}
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[1][i] == -1) {
			builder = builder + "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[1][i] < 10) {
				builder = builder + " " + std::to_string(this->scoresheet_array[1][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder = builder + std::to_string(this->scoresheet_array[1][i]);
			}

			if (i == 8 || i == 9) {
				builder = builder + "%";
			}

			else {
				builder = builder + "|";
			}
		}
	}

	builder = builder + "\n";

	//row 3 Y
	builder = builder + "         ----------------------------------   \nYellow:  |";
	for (int i = 0; i < 12; i++) {
		//boxed out on the side
		if (this->scoresheet_array[2][i] == -2) {
				builder = builder + "   ";
		}

		//boxed out in the middle of sheet
		else if (this->scoresheet_array[2][i] == -1) {
			builder = builder + "XX|";
		}

		//not boxed out
		else {
			//single digits prints like: 9| 5| with space after |
			if (this->scoresheet_array[2][i] < 10) {
				builder = builder + " " + std::to_string(this->scoresheet_array[2][i]);
			}

			//else double digit prints like: 10|11 with no space after |
			else {
				builder = builder + std::to_string(this->scoresheet_array[2][i]);
			}

			if (i == 2 || i == 3 || i == 10) {
				builder = builder + "%";
			}

			else {
				builder = builder + "|";
			}
		}
	}

	//we handle the failed throws print here (i.e. row 3)

	builder = builder + "\nFailed throws: ";

	for (int i = 0; i < 12; i++) {
		if (this->penalties != 0) {
			if (this->scoresheet_array[3][i] != 0) {
				builder = builder + std::to_string(this->scoresheet_array[3][i]);
			}
		}
	}

	myStream << builder << std::endl;
}

#ifdef TEST_SCORESHEET

int main(int argc, char **argz) {
	std::cout << "Test Scoresheet" << std::endl;
	
	Scoresheet myScoresheet = Scoresheet();
	myScoresheet.print(cout);

	//remove this eventually, for my own testing in Visual Studio because it's stupid
	//system("PAUSE");

	return 0;
}

#endif
