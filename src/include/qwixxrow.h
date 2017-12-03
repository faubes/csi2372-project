#pragma once

#include "colour.h"
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>


template<typename T, const Colour C>
class QwixxRow {

    public:

        bool locked = false;
        
        // stores value of last score entered
        int last = 0;
        
        // points to cell in which last entry was scored
        typename T::iterator it;
        
        QwixxRow();

        T qwixxContainer{};

        void add(int i);
        
        Colour getColour() const;
        
        // TODO: should be removed eventually
        T getContainer() { return qwixxContainer; }

        // helper tests if row contains value
        bool contains(const RollOfDice &rod) const;

        //+= operator to add RollOfDice of size 2, error checking throw exception on error
        QwixxRow<T,C>& operator+=(const RollOfDice& rod) {
            int val = static_cast<int>(rod);
            if (!rod.size() == 2)
                throw "Can't add more than two dice to QwixxRow";
            if ((last != 0) && (last >= val))
                throw "Can't score in this QwixxRow";
            for (auto &v : qwixxContainer) {
                if (v == val) {
                    it = &v;
                    last = v;
                    v = 0;
                }
            }
            if (it == (qwixxContainer.end() -1)) {
				locked = true;
			}
            return *this;
        }

		// returns value of last entry score in the row
		int getLast() const { return last; }

		// methods that return iterators to container
		// allowing for range loops
        using iterator = typename T::iterator;
        using const_iterator = typename T::const_iterator;

        iterator begin() {
            return qwixxContainer.begin();
        }
        iterator end() {
            return qwixxContainer.end();
        }
        const_iterator begin() const {
            return qwixxContainer.begin();
        }
        const_iterator end() const {
            return qwixxContainer.end();
        }
        const_iterator cbegin() const {
            return qwixxContainer.cbegin();
        }
        const_iterator cend() const {
            return qwixxContainer.cend();
        }
        
        bool operator!() const { return !locked; }
        
        template <typename T1, const Colour C1>
        friend std::ostream& operator<<(std::ostream& os, const QwixxRow<T1, C1>& qr);
};

template <typename T, const Colour C>
void QwixxRow<T, C>::add(int i) {
    qwixxContainer.push_back(i);
}

template <typename T, const Colour C>
Colour QwixxRow<T, C>::getColour() const {
    return C;
}

template <typename T, const Colour C>
QwixxRow<T, C>::QwixxRow() {
    //qwixxContainer.push_back(0);
}

template <typename T, const Colour C>
std::ostream& operator<<(std::ostream& os, const QwixxRow<T, C>& qr) {
    std::stringstream line1, line2, line3;
	for (const auto &x : qr) {
        if (x != 0) {
            line1 << "----";
            line2 << "|" << std::setw(2) << x <<"|";
            line3 << "----";
        }
        else {
            line1 << "----";
            line2 << "|XX|";
            line3 << "----";
        }
    }
    os << std::left << std::setw(10) << "" << line1.str() << std::endl;
    os << std::setw(10) << colour_to_string(qr.getColour()) << line2.str() << std::endl;
    os << std::setw(10) << "" << line3.str() << std::endl;
    return os;
}

template <typename T, const Colour C>
bool QwixxRow<T,C>::contains(const RollOfDice &rod) const {
	auto elem = std::find(qwixxContainer.begin(), qwixxContainer.end(), static_cast<int>(rod));
    return (elem != qwixxContainer.end());
}
