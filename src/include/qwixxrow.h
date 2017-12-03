#pragma once

#include "colour.h"
#include <vector>
#include <list>

template<typename T, const Colour C>
class QwixxRow {

public:
	QwixxRow();

	T qwixxContainer{};
	const Colour colour;

	void add(int i);
	Colour getColour();
	T getContainer() { return qwixxContainer;  }

	//+= operator to add RollOfDice of size 2, error checking throw exception on error

	template <typename T, const Colour c>
	friend std::ostream& operator<<(std::ostream& os, const QwixxRow<T, C>& qr);
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

	std::cout << colour_to_string(qr.colour) << " container size: " << qr.qwixxContainer.size() << std::endl;

	for (auto v : qr.qwixxContainer)
		std::cout << v << " ";

	return os;
}