#pragma once

#include "colour.h"

template <typename Colour> 
class QwintoRow {
	int qwintoArray[12];
	Colour c;

	public:
		int& operator[] (const int index);
		bool validate(RollOfDice myRoll, int index);

		//overload insertion operator print for ScoreSheet

};