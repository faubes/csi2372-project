
// main file with game loop, tests


#define TEST_COLOUR
#define TEST_RANDOMDICE
#define TEST_ROLLOFDICE

#include "colour.h"
#include "randomdice.h"
#include "rollofdice.h"
#include <iostream>


int main() {
	
#ifdef TEST_COLOUR
    std::vector<Colour> colours = {Colour::RED, Colour::YELLOW};
    for (Colour c : colours) {
		std::cout << colour_to_string(c) << std::endl;
	}
#endif

#ifdef TEST_RANDOMDICE
    for (int n=0; n<10; ++n)
        std::cout << RandomDice::get() << ' ';
    std::cout << '\n';
#endif

#ifdef TEST_ROLLOFDICE
    std::vector<Colour> colours2 = {Colour::RED, Colour::YELLOW};
    RollOfDice rd(colours2);
    rd.roll();
    std::cout << rd << std::endl;
#endif

}
