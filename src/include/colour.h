#ifndef COLOUR
#define COLOUR

#include <string>

enum class Colour {RED, YELLOW, BLUE, GREEN, WHITE};

// Helper method converts Colour to string
static std::string colour_to_string(const Colour c) {
	switch (c) {
		case Colour::RED:
			return "red";
		case Colour::YELLOW:
			return "yellow";
		case Colour::BLUE:
			return "blue";
		case Colour::GREEN:
			return "green";
		case Colour::WHITE:
			return "white";
		default:
			return "invalid colour!";
	}
}

/* maybe add colour in console later
static string get_ascii_colour(Scoresheet::colour colour) {
		switch (colour) {
			case Scoresheet::colour::RED:
				return "\x1b[;31m";
			case Scoresheet::colour::BLUE:
				return "\x1b[;34m";
			case Scoresheet::colour::YELLOW:
				return "\x1b[;33m";
			default:
				return "\x1b[;30;40m";
	}
}
*/
#endif
