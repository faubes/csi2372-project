
// randomdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

#include "randomdice.h"
#include <random>

// initialize static members
//Will be used to obtain a seed for the random number engine
std::random_device RandomDice::rd;
//Standard mersenne_twister_engine seeded with rd()
std::mt19937_64 RandomDice::gen(rd());
std::uniform_int_distribution<> RandomDice::dis(1, 6);

// returns a new integer from [1,6] with uniform prob. dist.
int RandomDice::get() {
	return RandomDice::dis(RandomDice::gen);
}

