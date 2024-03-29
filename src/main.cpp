// main.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// main file with game loop, tests

// Main compile flag to play the game
#define GAMELOOP

// Various unit tests
//#define TESTS
#ifdef TESTS
//#define TEST_COLOUR
//#define TEST_RANDOMDICE
//#define TEST_ROLLOFDICE
//#define TEST_QWINTO_ROW
//#define TEST_QWINTO_SCORESHEET
//#define TEST_QWINTOPLAYER
#define TEST_QWIXX_SCORESHEET
#endif

#include "gameui.h"
#include "colour.h"
#include "randomdice.h"
#include "rollofdice.h"
#include "scoresheet.h"
#include "qwintorow.h"
#include "qwintoscoresheet.h"
#include "qwintoplayer.h"
#include "qwixxplayer.h"
#include "qwixxrow.h"
#include "qwixxscoresheet.h"
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

#ifdef TEST_QWIXX_SCORESHEET
	QwixxScoreSheet qws2("Art");
	std::cout << qws2;
	std::cout << qws2.setTotal() << std::endl;
#endif

#ifdef GAMELOOP
    std::cout << "Welcome to Qwinto / Qwixx!" << std::endl;

    // Ask player to choose game version
    bool qwinto =false, qwixx =false;
    while (!qwinto && !qwixx) {
        qwinto = getYesNo(std::cout, std::cin, "Would you like to play Qwinto?");
        if (!qwinto) {
            qwixx = getYesNo(std::cout, std::cin, "How about Qwixx, then?");
        }
        if (!qwinto & !qwixx) {
            std::cout << "Well then why did you load the game??" << std::endl;
        }
        std::cout << std::endl;
    }

    // number of players and names of players.
    int numPlayers = getInt(std::cout, std::cin, "How many players?", 2, 12);

    std::vector<Player*> players;

    // Create the corresponding players and RollOfDice for the game.
    RollOfDice rod;

    for (int i = 0; i < numPlayers; i++) {
        std::stringstream msg;
        msg << "What is player " << i << "\'s name? ";
        std::string name = getString(std::cout, std::cin, msg.str());
        if (qwinto) {
            players.emplace_back(new QwintoPlayer(name));
        } else {
            players.emplace_back(new QwixxPlayer(name));
        }
    }

    bool gameover = false;
    // while end condition is not reached
    while (!gameover) {
        for (auto & p : players) {
            std::cout << p->getName() << "\'s roll!" << std::endl;
            // next player takes a turn i.e., becomes active
            p->setActive(true);
            // get input from active player before roll
            p->inputBeforeRoll(rod);
            // roll dice and show result
            rod.roll();
            std::cout << rod;
            // print scoresheet of active player
            std::cout << *p;
            // get input from active player after roll
            // score dice according to input from active player
            p->inputAfterRoll(rod);
            std::cout << *p;

            // check if game is over
            if (!(*p)) gameover = true;

            std::cout << std::endl;

            // loop over all non-active players
            for (auto & inactiveplayer : players) {
                if (!inactiveplayer->isActive()) {
                    // print scoresheet of non-active player
                    std::cout << *inactiveplayer;
                    std::cout << "Enter score for roll: " << std::endl;
                    std::cout << rod;
                    // get input from non-active player
                    // score dice according to input
                    inactiveplayer->inputAfterRoll(rod);
                    std::cout << *inactiveplayer;
                    if (!(*inactiveplayer)) gameover = true;
                    std::cout << std::endl;
                }
            }
            p->setActive(false);
        }
    }
    // loop over all players
    for (auto & p : players) {
        // calculate points for player
        std::cout << p->getName();
        std::cout << "\'s score: " << p->getScore() << std::endl;
    }

#endif
    //for stupid Visual Studio
    system("Pause");
}
