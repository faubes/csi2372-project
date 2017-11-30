// main file with game loop, tests
//#define TEST_COLOUR
//#define TEST_RANDOMDICE
#define TEST_ROLLOFDICE
//#define TEST_QWINTO_ROW
#define TEST_QWINTO_SCORESHEET

#include "colour.h"
#include "randomdice.h"
#include "rollofdice.h"
#include "scoresheet.h"
#include "qwintorow.h"
#include "qwintoscoresheet.h"
#include <iostream>


int main() {

#ifdef TEST_COLOUR
	std::vector<Colour> colours = { Colour::RED, Colour::YELLOW };
	for (Colour c : colours) {
		std::cout << colour_to_string(c) << std::endl;
	}
#endif

#ifdef TEST_RANDOMDICE
	for (int n = 0; n<10; ++n)
		std::cout << RandomDice::get() << ' ';
	std::cout << '\n';
#endif

#ifdef TEST_ROLLOFDICE
	std::vector<Colour> colours2 = { Colour::RED, Colour::YELLOW };
	RollOfDice rd(colours2);
	rd.roll();
	std::cout << rd << std::endl;
	std::cout << "Total value: " << static_cast<int>(rd) << std::endl;
#endif

#ifdef TEST_QWINTO_ROW
	//Test creation of a RED row
	QwintoRow<Colour::RED> redRow;

	std::cout << redRow.validate(rd, 3) << std::endl;

	std::cout << redRow.validate(rd, 2) << std::endl;
	
	//array should remain the same
	std::cout << redRow.getColour() << std::endl;
	for (int i = 0; i < 12; i++) {
		std::cout << redRow[i];
	}

	std::cout << std::endl;

#endif

#ifdef TEST_QWINTO_SCORESHEET
	QwintoScoreSheet qws;
	ScoreSheet& ss = qws;

	//calling from ss gives parent class for score()
	std::cout << "Score (T/F): " << qws.score(rd,Colour::RED,2) << std::endl;
	std::cout << qws << std::endl;

#endif

	//for stupid Visual Studio
	system("Pause");
}
