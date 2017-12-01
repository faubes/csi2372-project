// gameui.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// functions to help with getting and validating user input

#include <iostream>
#include <string>
#include <algorithm>

bool getYesNo(std::ostream& os, std::istream& is, std::string msg) {
	std::string input;
	bool res;
	os << msg << " " << "[Y/N]: ";
	for (;;) {
		if (is >> input) {
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);
			if (input == "yes" || input == "y") {
				res = true;
				break;
			}
			if (input == "no" || input == "n") 
			{
				res = false;
				break;
			}
		os << msg << " " << "[Y/N]: ";
		is.clear();
		}
	}
	return res;
}
