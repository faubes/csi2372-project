#pragma once

#include "colour.h"
#include <vector>
#include <list>

template<typename T, const Colour C>
class QwixxRow {

public:

	bool locked = false;
	int last = 0;
	QwixxRow();

	T qwixxContainer{};
	const Colour colour;

	void add(int i);
	Colour getColour();
	T getContainer() { return qwixxContainer;  }

	//+= operator to add RollOfDice of size 2, error checking throw exception on error	
	QwixxRow<T,C>& operator+=(const RollOfDice& rod) {
		int val = static_cast<int>(rod);
		if (!rod.size() == 2) 
			throw "Can't add more than two dice to QwixxRow";
		if ((last != 0) && (last >= val)) 
			throw "Can't score in this QwixxRow";
			for (auto &v : qwixxContainer) {
				if (v == val) {
					last = v;
					v = 0;
				}
			}
		return *this;
	}
	
	template <typename T1, const Colour C1>
	friend std::ostream& operator<<(std::ostream& os, const QwixxRow<T1, C1>& qr);
};

template <typename T, const Colour C>
void QwixxRow<T, C>::add(int i) {
	qwixxContainer.push_back(i);
}

template <typename T, const Colour C>
Colour QwixxRow<T, C>::getColour() {
	return colour;
}

template <typename T, const Colour C>
QwixxRow<T, C>::QwixxRow() : colour(C) {
	//testing
	//qwixxContainer.push_back(0);
}

template <typename T, const Colour C>
std::ostream& operator<<(std::ostream& os, const QwixxRow<T, C>& qr) {
	//std::cout << colour_to_string(qr.colour) << " container size: " << qr.qwixxContainer.size() << std::endl;
	for (const auto &v : qr.qwixxContainer)
		os << v << " ";
	return os;
}
