// scoresheet.h
/* 
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/
#define TEST_SCORESHEET
#include "scoresheet.h"


int Scoresheet::cardcount = 0;

Scoresheet::Scoresheet() :
		Scoresheet("Player " + (++Scoresheet::cardcount))
{};

Scoresheet::Scoresheet(std::string str) :
	player_name(str) {
		Scoresheet::cardcount++;
				
};


#ifdef TEST_SCORESHEET
int main(int argc, char **argz) {
	std::cout << "Test Scoresheet" << std::endl;
	return 0;
	}

#endif
