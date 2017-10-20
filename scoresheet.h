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

class Scoresheet {

static cardcount = 0;

int scoresheet_array[3][12] { };
int penalties = 0;
std::string player_name;

Scoresheet(std::string player_name = ("Player " + cardcount));


// prints the scoresheet	
print
// player writes to scoresheet : requires vector of dice and position in scoresheet array
score
// calculate final score
calculate_score

}

#endif
