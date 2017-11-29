#pragma once

#include "colour.h"
#include <iostream>

template <typename Colour> 
class QwintoRow {
	private:
		int qwintoArray[12]{};
		Colour c;

	public:
		QwintoRow(Colour colour);
		//int& operator[] (const RollOfDice myRoll); //for inserting a value into the row array
		//bool validate(const RollOfDice myRoll, const int index);
		int getValueAtindex(const int index);
		std::string getColour();

		//overload insertion operator print for ScoreSheet

		//I need destructor, copy, assignment
};

template <typename Colour>
QwintoRow<Colour>::QwintoRow(Colour colour) {
	c = colour;

	if (colour == Colour::RED) {
		qwintoArray[0] = -1;
		qwintoArray[1] = -1;
	}

	else if (colour == Colour::YELLOW) {
		qwintoArray[0] = -1;
		qwintoArray[11] = -1;
	}

	else if (colour == Colour::BLUE) {
		qwintoArray[10] = -1;
		qwintoArray[11] = -1;
	}

	else {
		std::cout << "Error in initializing qwintoArray" << std::endl;
	}
}

//--------------------------TESTING PURPOSES

template <typename Colour>
int QwintoRow<Colour>::getValueAtindex(const int index) {
	return qwintoArray[index];
}

template <typename Colour>
std::string QwintoRow<Colour>::getColour() {
	return colour_to_string(c);
}