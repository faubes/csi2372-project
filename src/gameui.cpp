// gameui.cpp
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/

// functions to help with getting and validating user input
#include "gameui.h"

bool getYesNo(std::ostream& os, std::istream& is, std::string msg) {
    std::string input;
    bool res;
    for (;;) {
        os << msg << " " << "[Y/N]: ";

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
        } else {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }
    return res;
}

int getInt(std::ostream& os, std::istream& is, std::string msg, int low, int high) {
    int res;
    for (;;) {
        os << msg << " [" << low << ".." << high << "]: ";
        if (is >> res) {
            if (res >= low & res <= high) {
                break;
            }
        } else {
            os << "That's not a valid number" << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    os << "You entered " << res << std::endl;
    return res;
}

std::string getString(std::ostream& os, std::istream& is, std::string msg) {
    std::string input;
    for (;;) {
        os << msg << ": ";
        if (is >> input) {
            if (input.size() > 0) {
                break;
            }
        } else {
            os << "That's not a valid input" << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    os << "You entered " << input << std::endl;
    return input;
}
