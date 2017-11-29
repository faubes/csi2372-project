// qwintorow.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef QWINTOROW
#define QWINTOROW

#include "colour.h"
#include <iostream>
#include <array>
#include <sstream>
#include <iomanip>

template <const Colour C> 
class QwintoRow {
	private:
		using fixed_array = std::array<int, 12>;
		// array for scores
		fixed_array qwintoArray{};
		const Colour colour;
		
	public:
		//constructor
		QwintoRow();
		//bool validate(const RollOfDice myRoll, const int index);
		
		std::string getColour() const;

		//overload insertion operator print for ScoreSheet

		// overloads subscript operator for access to array
		int& operator[] (const int index) {
			return qwintoArray[index];
		}
		
		// methods needed to enable range loops over RoD
		using iterator = fixed_array::iterator;
		using const_iterator = fixed_array::const_iterator;

		iterator begin() { return qwintoArray.begin(); }
		iterator end() { return qwintoArray.end(); }
		const_iterator begin() const { return qwintoArray.begin(); }
		const_iterator end() const { return qwintoArray.end(); }
		const_iterator cbegin() const { return qwintoArray.cbegin(); }
		const_iterator cend() const { return qwintoArray.cend(); }
		
		template <const Colour c>
		friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& qr);
		
		//I need destructor, copy, assignment
};

template <const Colour C>
QwintoRow<C>::QwintoRow() : colour(C) {
	
	if (C == Colour::RED) {
		qwintoArray[0] = -1;
		qwintoArray[1] = -1;
	}

	else if (C == Colour::YELLOW) {
		qwintoArray[0] = -1;
		qwintoArray[11] = -1;
	}

	else if (C == Colour::BLUE) {
		qwintoArray[10] = -1;
		qwintoArray[11] = -1;
	}

	else {
		std::cout << "Error in initializing qwintoArray" << std::endl;
	}
}

template <Colour C>
std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& qr) {
	std::stringstream line1, line2, line3;
	for (auto &x : qr) {
		if (x == -1) {
			line1 << "    ";
			line2 << "    ";
			line3 << "    ";
		}
		else if (x == 0 ) {
			line1 << "----";
			line2 << "|  |";
			line3 << "----";
		}
		else {
			line1 << "----";
			line2 << "|" << std::setw(2) << x << "|";
			line3 << "----";
		}
	}
	os << "\t" << line1.str() << std::endl; 
	os << "\t" << line2.str() << std::endl;
	os << "\t" << line3.str() << std::endl;
	return os;
}


template <const Colour C>
std::string QwintoRow<C>::getColour() const {
	return colour_to_string(colour);
}

#endif
