// dice.h
/*
*  CSI 2372 -  Fall 2017
*  Project
*  github.com/faubes
*  github.com/agbleung
*/	

#include "dice.h"

// Dice::Dice() {}

Dice::Dice(const Colour _c) : c(_c), face(0) {}

void Dice::roll() {
	face = RandomDice::get();
}

// Prints the dice to ostream
// Credit to 
//  https://codegolf.stackexchange.com/questions/2602/draw-dice-results-in-ascii/2649
// for the ascii art
ostream& operator<<(ostream& os, const Dice& d)  
{  
    switch(d.face) {
    
    case 1:
		os << "-----" << std::endl;
		os << "|   |" << std::endl;
		os << "| o |" << std::endl;
		os << "|   |" << std::endl;
		os << "-----" << std::endl;
		break;
	
	case 2:
		os << "-----" << std::endl;
		os << "|o  |" << std::endl;
		os << "|   |" << std::endl;
		os << "|  o|" << std::endl;
		os << "-----" << std::endl;
		break;

	case 3:
		os << "-----" << std::endl;
		os << "|o  |" << std::endl;
		os << "| o |" << std::endl;
		os << "|  o|" << std::endl;
		os << "-----" << std::endl;
		break;

	case 4:
		os << "-----" << std::endl;
		os << "|o o|" << std::endl;
		os << "|   |" << std::endl;
		os << "|o o|" << std::endl;
		os << "-----" << std::endl;
		break;
		
	case 5:
		os << "-----" << std::endl;
		os << "|o o|" << std::endl;
		os << "| o |" << std::endl;
		os << "|o o|" << std::endl;
		os << "-----" << std::endl;
		break;
		
	case 6:
		os << "-----" << std::endl;
		os << "|o o|" << std::endl;
		os << "|o o|" << std::endl;
		os << "|o o|" << std::endl;
		os << "-----" << std::endl;
		break;
		
	default:
		os << "Whoops! Broken dice" << std::endl;
    }
    
    return os;  
}  
