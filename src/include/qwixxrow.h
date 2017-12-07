// qwixxrow.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

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

        // number of values scored
        int counter = 0;

        // points to cell in which last entry was scored
        // typename T::iterator it;

        QwixxRow();

        T qwixxContainer{};

        void add(int i);

        Colour getColour() const;

        //+= operator to add RollOfDice of size 2, error checking throw exception on error
        QwixxRow<T,C>& operator+=(const RollOfDice& rod) {
            std::stringstream errmsg;
            int val = static_cast<int>(rod);
            if (!rod.size() == 2) {
                errmsg << "Can't add more than two dice to QwixxRow" << std::endl;
                throw errmsg.str();
            }

            if ((C == Colour::RED) || (C == Colour::YELLOW)) {
                if ((last != 0) && (last >= val)) {
                    errmsg << "Can't score " << val << " in row "
                           << colour_to_string(C) << std::endl;
                    throw errmsg.str();
                }
            }
            else if ((C == Colour::BLUE) || (C == Colour::GREEN)) {
                if ((last != 0) && (last <= val)) {
                    errmsg << "Can't score " << val << " in row "
                           << colour_to_string(C) << std::endl;
                    throw errmsg.str();
                }
            } else throw "trying to add to invalid row";

            for (auto &v : qwixxContainer) {
                if (v == val) {
                    counter++;
                    last = v;
                    v = 0;
                }
            }
            if ((((C == Colour::RED) || (C == Colour::YELLOW)) && (last == 12) && (counter >= 5)) ||
                    (((C == Colour::BLUE) || (C == Colour::GREEN)) && (last == 2) && (counter >= 5))) {
                locked = true;
                std::cout << "locking since colour: " << colour_to_string(C) << std::endl;
                std::cout << "last: " << last << " counter: " << counter << std::endl;
            }
            return *this;
        }

        // returns value of last entry score in the row
        int getLast() const {
            return last;
        }

        //get counter
        int getCounter() const {
            return counter;
        }

        //remove this later set counter
        /*void setCounter(int i) {
        	counter = i;
        }*/

        //get locked
        bool getLocked() const {
            return locked;
        }

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
        bool operator!() const {
            return locked;
        }

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


    os << std::left << std::setw(10) << "" << line1.str() << "---" << std::endl;
    if (qr.getLocked() == true) {
        os << std::setw(10) << colour_to_string(qr.getColour()) << line2.str() << " L " << std::endl;
    }

    else {
        os << std::setw(10) << colour_to_string(qr.getColour()) << line2.str() << " U " << std::endl;
    }
    os << std::setw(10) << "" << line3.str() << "---" << std::endl;
    return os;
}
