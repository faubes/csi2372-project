// gameui.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// functions to help with getting and validating user input
#ifndef GAMEUI
#define GAMEUI

#include <iostream>
#include <string>
#include <algorithm>

bool getYesNo(std::ostream& os, std::istream& is, std::string msg);

int getInt(std::ostream& os, std::istream& is, std::string msg, int low, int high);

std::string getString(std::ostream& os, std::istream& is, std::string msg);

#endif
