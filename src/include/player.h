// player.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// provides functions for console input and output to a player.

#ifndef PLAYER
#define PLAYER

#include <string>
#include "rollofdice.h"

class Player {
    protected:
        bool active = false;
        std::string name;
        virtual void print(std::ostream& myStream) const = 0;
    public:
        Player(const std::string& n) : name(n) {}
        virtual void inputBeforeRoll(RollOfDice& rod) = 0;
        virtual void inputAfterRoll(const RollOfDice& rod) = 0;
        void setActive(bool b) {
            active = b;
        }
        bool isActive() const {
            return active;
        }
        friend ostream& operator<<(ostream& os, const Player& p)
        {
            p.print(os);
            return os;
        }
        virtual bool operator!() const = 0;
};

#endif
