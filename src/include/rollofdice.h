// rollofdice.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef ROLLOFDICE
#define ROLLOFDICE

#include "dice.h"
#include "colour.h"
#include <vector>
#include <set>
#include <iostream>

using std::ostream;

class RollOfDice {
        std::vector<Dice> rod;

    public:
        RollOfDice();
		RollOfDice(const std::vector<Colour>& colours);
        void addDice(const Dice& d);
		
        RollOfDice getPair(int i, int j) const;
        
		RollOfDice getWhitePair() const;

		
        void roll();
		size_t size() const { return rod.size(); }
		
        // methods needed to enable range loops over RoD
        using iterator = std::vector<Dice>::iterator;
        using const_iterator = std::vector<Dice>::const_iterator;

		void clear() { rod.clear(); }
		
        iterator begin() {
            return rod.begin();
        }
        iterator end() {
            return rod.end();
        }
        const_iterator begin() const {
            return rod.begin();
        }
        const_iterator end() const {
            return rod.end();
        }
        const_iterator cbegin() const {
            return rod.cbegin();
        }
        const_iterator cend() const {
            return rod.cend();
        }

		// overloads subscript operator for access to array
        Dice operator[] (const int index) const {
            return rod[index];
        }

        // converts roll to int by summing face values
        operator int() const;


        friend ostream& operator<<(ostream& os, const RollOfDice& rod);

};

#endif
