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
#include <algorithm>

template <const Colour C>
class QwintoRow {
    private:
        using fixed_array = std::array<int, 12>;
        // array for scores
        fixed_array qwintoArray{};


    public:
        //constructor
        QwintoRow();

        // returns numer of filled cells in a row
        int row_complete() const;

        // returns true if row is full
        bool isFull() const;

        // checks if adding a score to index preserves ascending requirement
        bool validateRow(const RollOfDice& myRoll, const int index);

        // returns colour of row
        std::string getColour() const;

        // helper tests if row contains value
        bool contains(const RollOfDice &rod) const;

        // overloads subscript operator for access to array
        int& operator[] (const int index) {
            return qwintoArray[index];
        }

        // returns max value of the row
        int getMax() const;

        // methods needed to enable range loops over RoD
        using iterator = fixed_array::iterator;
        using const_iterator = fixed_array::const_iterator;

        iterator begin() {
            return qwintoArray.begin();
        }
        iterator end() {
            return qwintoArray.end();
        }
        const_iterator begin() const {
            return qwintoArray.begin();
        }
        const_iterator end() const {
            return qwintoArray.end();
        }
        const_iterator cbegin() const {
            return qwintoArray.cbegin();
        }
        const_iterator cend() const {
            return qwintoArray.cend();
        }

        //overload insertion operator print for ScoreSheet
        template <const Colour C1>
        friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C1>& qr);
};

template <const Colour C>
QwintoRow<C>::QwintoRow() {

    if (C == Colour::RED) {
        qwintoArray[0] = -1;
        qwintoArray[1] = -1;
        qwintoArray[5] = -1;
    }

    else if (C == Colour::YELLOW) {
        qwintoArray[0] = -1;
        qwintoArray[6] = -1;
        qwintoArray[11] = -1;
    }

    else if (C == Colour::BLUE) {
        qwintoArray[4] = -1;
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

    int counter = 0;

    for (auto &x : qr) {
        if (x == -1) {
            if (((C == Colour::RED) && (counter == 5)) || 
				((C == Colour::YELLOW) && (counter == 6)) || 
				((C == Colour::BLUE) && (counter == 4))) {
                line1 << "----";
                line2 << " XX|";
                line3 << "----";
            }
            else {
                line1 << "    ";
                line2 << "    ";
                line3 << "    ";
            }
        }
        else {
            char endCell;

            if (((C == Colour::RED) && ((counter == 2) || (counter == 3) || (counter == 6) || (counter == 7))) ||
                    ((C == Colour::YELLOW) && ((counter == 7) || (counter == 8))) ||
                    ((C == Colour::BLUE) && ((counter == 1) || (counter == 2) || (counter == 8) || (counter == 9)))) {
                endCell = '%';
            }

            else {
                endCell = '|';
            }


            if (x == 0) {
                if (((C == Colour::RED) && (counter == 2)) ||
                        ((C == Colour::YELLOW) && (counter == 1)) ||
                        ((C == Colour::BLUE) && (counter == 0))) {
                    line1 << "----";
                    line2 << "|  " << endCell;
                    line3 << "----";
                }

                else {
                    line1 << "----";
                    line2 << "   " << endCell;
                    line3 << "----";
                }
            }

            else {
                if (((C == Colour::RED) && (counter == 2)) ||
                        ((C == Colour::YELLOW) && (counter == 1)) ||
                        ((C == Colour::BLUE) && (counter == 0))) {
                    line1 << "----";
                    line2 << "|" << std::setw(2) << x << endCell;
                    line3 << "----";
                }

                else {
                    line1 << "----";
                    line2 << " " << std::setw(2) << x << endCell;
                    line3 << "----";
                }
            }
        }

        counter++;
    }
    os << std::left << std::setw(10) << "" << line1.str() << std::endl;
    os << std::setw(10) << qr.getColour() << line2.str() << std::endl;
    os << std::setw(10) << "" << line3.str() << std::endl;
    return os;
}


// Returns string rep. of colour
template <const Colour C>
std::string QwintoRow<C>::getColour() const {
    return colour_to_string(C);
}

// Helper method to test if a row contains a value
template <const Colour C>
bool QwintoRow<C>::contains(const RollOfDice &rod) const {
    auto elem = std::find(qwintoArray.begin(), qwintoArray.end(), static_cast<int>(rod));
    return (elem != qwintoArray.end());
}

// Function tests if a given roll value can be placed in the row
template <const Colour C>
bool QwintoRow<C>::validateRow(const RollOfDice& rod, const int index) {
    // if cell is non zero then either it's already filled or it's an invalid cell
    if (qwintoArray[index] != 0) {
        return false;
    }

    // if value is already in the row, then no good.
    if (contains(rod)) {
        return false;
    }
    std::array<int, 12> temp = qwintoArray;

    temp[index] = static_cast<int>(rod);

    std::vector<int> values;

    // filter out zeroes and negatives
    for (int i = 0; i < 12; i++) {
        if (temp[i] > 0) {
            values.emplace_back(temp[i]);
        }
    }
    // create copy of values
    std::vector<int> original(values);
    // sort values
    std::sort(values.begin(), values.end());
    // check if original == sorted
    return original == values;
}


// scans array to count filled cells
template <const Colour C>
int QwintoRow<C>::row_complete() const {
    int counter = 0;

    for (int i = 0; i < 12; i++) {
        if (qwintoArray[i] > 0) {
            //then all filled in cells
            counter++;
        }
    }
    return counter;
}

// QOL method to test for full row
template <const Colour C>
bool QwintoRow<C>::isFull() const {
    return row_complete() == 9;
}

template <const Colour C>
int QwintoRow<C>::getMax() const {
    return *std::max_element(qwintoArray.begin(), qwintoArray.end());
}

#endif
