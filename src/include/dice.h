// dice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#ifndef DICE
#define DICE

#include "randomdice.h"
#include "colour.h"
#include <iostream>

using std::ostream;

class Dice {
        const Colour c;
        int face;

    public:
        // Dice();
        Dice(const Colour _c);
        void roll();
        friend ostream& operator<<(ostream& os, const Dice& d);
        Colour getColour() const {
            return c;
        }
        int getValue() const {
            return face;
        }
};

#endif
