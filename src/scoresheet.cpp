// scoresheet.cpp
/* 
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/
#define TEST_SCORESHEET
#include "scoresheet.h"

using std::cout;
using std::endl;
using std::string;

// tally of created scoresheets
int Scoresheet::count = 0;

// default constructor names player "Player i"
Scoresheet::Scoresheet() :
		Scoresheet(string("Player ") + std::to_string(Scoresheet::count +1))
{ };

// constructor with custom name
Scoresheet::Scoresheet(std::string str) :
	player_name(str) {
		Scoresheet::count++;				
};

// print defaults to cout
void Scoresheet::print() { print(cout); };

// print object to ostream
void Scoresheet::print(std::ostream &os) {
	os << "Player name: " << this->player_name << endl;
	for (int i=0; i < 3; i ++) {
		for (int j=0; j < 12; j++) {
			os << Scoresheet::scoresheet_array[i][j] << " ";
		}
		os << endl;
	}
};

#ifdef TEST_SCORESHEET
int main(int argc, char **argz) {
	Scoresheet s1;
	
	cout << "Test Scoresheet" << endl;
	cout << s1.getName() << endl;
	s1.print();
	return 0;
	}

#endif
