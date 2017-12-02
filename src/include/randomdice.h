// randomdice.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/


// To use: include "randomdice.h"
// and invoke
// RandomDice::get()


// One of the requirements for the project
// is a helper class with static objects
// to help with uniform random number generation
// i.e., have a nice simulation of dice.

// This code is basically copypasta from
// http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
// wrapped into static objects.

#ifndef RANDOMDICE
#define RANDOMDICE

#include <random>

class RandomDice {

        static std::random_device rd;  //Will be used to obtain a seed for the random number engine
        static std::mt19937_64 gen; //Standard mersenne_twister_engine seeded with rd()
        static std::uniform_int_distribution<int> dis;
    public:
        static int get();
};


#endif

