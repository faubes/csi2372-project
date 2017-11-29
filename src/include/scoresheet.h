// scoresheet.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef SCORESHEET
#define SCORESHEET

#include "colour.h"
#include "rollofdice.h"
#include <iostream>
#include <string>

using std::iostream;
using std::string;

//Base class
//The class ScoreSheet is the abstract parent class for the two different score sheets in Qwixx and Qwinto.

class ScoreSheet {
	// default private
	// It needs to hold the name of the player, the number of failed attempts and the overall score.
	std::string player_name;
	int failed_attempts = 0;
	int total_score = 0;

protected:
	// The function score is to call the protected pure virtual function validate internally.
	virtual bool validate()=0;

	// Another function is setTotal which calls the pure virtual function calcTotal
	virtual int calcTotal()=0;

	// method to be overloaded to provide polymorphic behaviour for the global << operator
	virtual void print(std::ostream& myStream) const;

	// Finally, the not operator should be virtual and to return true if the ScoreSheet indicates that the game has ended.
	virtual bool operator!() const;

public:
	/* A score should be entered by the function score which accepts a RollOfDice and the user selected
		colour and position counted from the left.The position should have a default parameter of - 1 which is to
		mean that the position info is not used when the game Qwixx is played.Score is to return a boolean
		indicating if the Dice can be scored.*/
	// this will call pure virtual validate() internally
	bool score(RollOfDice roll, Colour c, int position = -1); //these need to be implemented still

	/* Another function is setTotal which calls the pure virtual function calcTotal, 
		sets and returns the points for the final score.*/
	// calls pure virtual calcTotal, sets total, returns total
	int setTotal() {
		total_score = calcTotal();
		return total_score;
	}

	//https://stackoverflow.com/questions/15786169/global-operators-and-polymorphism
	/* You need to overload the insertion operator for
		the class ScoreSheet for printing. This global operator should behave polymorphically, even though,
		there is no polymorphism for global operators and functions.*/
	friend std::ostream& operator << (std::ostream& os, const ScoreSheet& scoresheet) {
		scoresheet.print(os);
		return os;
	}
};

// children
// QwintoScoreSheet
// QwixxScoreSheet

#endif
