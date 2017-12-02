// main file with game loop, tests
//#define TEST_COLOUR
//#define TEST_RANDOMDICE
//#define TEST_ROLLOFDICE
//#define TEST_QWINTO_ROW
//#define TEST_QWINTO_SCORESHEET
#define TEST_QWINTOPLAYER

#include "colour.h"
#include "randomdice.h"
#include "rollofdice.h"
#include "scoresheet.h"
#include "qwintorow.h"
#include "qwintoscoresheet.h"
#include "qwintoplayer.h"
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
    QwintoRow<Colour::YELLOW> yellowRow;

    std::cout << redRow.row_complete() << std::endl;
    std::cout << yellowRow.row_complete() << std::endl;

    //array should remain the same
    std::cout << redRow.getColour() << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << redRow[i];
    }

    std::cout << std::endl;

#endif

#ifdef TEST_QWINTO_SCORESHEET
    QwintoScoreSheet qws("Art");
    ScoreSheet& ss = qws;
    std::vector<Colour> colours3 = { Colour::RED, Colour::YELLOW };
    RollOfDice rd2(colours3);
    rd2.roll();

    //calling from ss gives parent class for score()
    ss.incrementFailedThrows();
    ss.incrementFailedThrows();
    ss.incrementFailedThrows();

    //std::cout << "Score (T/F): " << ss.score(rd2, Colour::RED, 2) << std::endl;
    std::cout << "Set Total: " << ss.setTotal() << std::endl;
    std::cout << ss << std::endl;

#endif

#ifdef TEST_QWINTOPLAYER
    QwintoPlayer qp("Joe");
    RollOfDice rod;
    qp.inputBeforeRoll(rod);
    std::cout << rod;
    std::cout << qp;
    qp.inputAfterRoll(rod);
    std::cout << qp;
#endif
    //for stupid Visual Studio
    system("Pause");
}
