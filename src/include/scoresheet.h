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
// using std::vector;
using std::string;

class Scoresheet {

const int rows = 3;
const int cols = 12;

static int count;

enum class colour { red, yellow, blue };

int scoresheet_array[rows][cols] { };

int penalties = 0;

std::string player_name;

public:

// Constructor
Scoresheet();
Scoresheet(string str);

// Copy constructor
// Scoresheet(Scoresheet &other);

// Move constructor
// Scoresheet(Scoresheet&& other);

// prints the scoresheet	
void print();
void print(std::ostream &os);

// player writes to scoresheet : requires vector of dice and position in scoresheet array
//void score(const std::vector<Dice> roll, const Scoresheet::Colour c, const int pos);

// calculate final score
//int calculate_score();

static int getCount() { return count; }

std::string getName() { return player_name; }

};

#endif
