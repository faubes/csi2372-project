// scoresheet.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef SCORESHEET
#define SCORESHEET

#include <iostream>
#include <vector>
#include <string>

using std::iostream;
using std::vector;
using std::string;


/*class Dice {
// it will just house the RNG logic for dice rolling, so has no member variables

public:
// Constructor
Dice();

// Methods probably will have a RNG that returns some number
void print();
};*/


class Scoresheet {

<<<<<<< Updated upstream
	
//	static const int rows = 3;
//	static const int cols = 12;
=======
	static string get_ascii_colour(Scoresheet::colour colour) {
		switch (colour) {
		case Scoresheet::colour::RED:
			return "\033[;31m";
		case Scoresheet::colour::BLUE:
			return "\033[;34m";
		case Scoresheet::colour::YELLOW:
			return "\033[;33m";
		default:
			return "\033[;30;40m";
		}

	}
>>>>>>> Stashed changes

	//	static const int rows = 3;
	//	static const int cols = 12;


	//row 0 is for RED, row 1 is for YELLOW, row 2 is for BLUE, row 3 is for failed throws
	int scoresheet_array[4][12]{};
	int penalties = 0;
	std::string player_name;
	static int count;

public:

	// just capitalizing this because Lang uses capitals in his class design
	enum class colour { RED, YELLOW, BLUE };

	static string get_ascii_colour(Scoresheet::colour colour) {
		switch(colour) {
			case Scoresheet::colour::RED:
				return "\x1b[;31m";
			case Scoresheet::colour::BLUE:
				return "\x1b[;34m";
			case Scoresheet::colour::YELLOW:
				return "\x1b[;33m";
			default:
				return "\x1b[;30;40m";
		}		
	}
	
	// Constructor
	Scoresheet();
	Scoresheet(string str);

	// Copy constructor
	// Scoresheet(Scoresheet &other);

	// Move constructor
	// Scoresheet(Scoresheet&& other);

	// prints the scoresheet	
	void print(std::ostream& myStream);
	void print() { print(std::cout); }

	// player writes to scoresheet : requires vector of dice and position in scoresheet array
	// this needs to call validate, if not okay we revert the change; 
	// some errors here in this function definition
	// void score(const std::vector<Dice> roll, const Scoresheet::colour c, const int pos);
	void score(const int roll, const int row, const int col);


	// calculate final score
	int calculate_score();

	// validate (calls other validate methods as enumerated below)
	// boolean validate();

	// validate that entry is not 'boxed out' cell (sheared ones or XX) and that cell is not already filled in (i.e. still 0)
	const bool validate_cell(const int &row, const int &col);

	// validate column is unique
	const bool validate_col(const int &col);

	// validate row is ascending
	const bool validate_row(const int &row);

	static int getCount() { return count; }

	std::string getName() { return player_name; }

};

#endif
