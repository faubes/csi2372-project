
// randomdice.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// #define TEST_RANDOMDICE
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
	
#ifdef TEST_RANDOMDICE
#include <iostream>
int main() {
    for (int n=0; n<10; ++n)
        std::cout << RandomDice::get() << ' ';
    std::cout << '\n';
}
#endif
