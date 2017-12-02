#pragma once

#include "colour.h"
#include <vector>
#include <list>

template <class T, const Colour C>
class QwixxRow {
    public:
		QwixxRow();
		T qwixxContainer{};
		const Colour colour;

        //+= operator to add RollOfDice of size 2, error checking throw exception on error

		template <class T1, const Colour C1>
		friend std::ostream& operator<<(std::ostream& os, const QwixxRow<T1,C1>& qr);
};


template <class T, const Colour C>
QwixxRow<T,C>::QwixxRow() : colour(C) {
	//testing
	//qwixxContainer.push_back(0);
}

template <class T, const Colour C>
std::ostream& operator<<(std::ostream& os, const QwixxRow<T, C>& qr) {

	std::cout << "Container size: " << qr.qwixxContainer.size() << std::endl;

	for (auto v : qr.qwixxContainer)
		std::cout << v << "\n";

	return os;
}
