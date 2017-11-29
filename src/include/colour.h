#ifndef COLOUR
#define COLOUR

#include <string>

enum class Colour { RED, YELLOW, BLUE, GREEN, WHITE };

// Helper method converts Colour to string
static std::string colour_to_string(const Colour c) {
	switch (c) {
	case Colour::RED:
		return "Red";
		break;
	case Colour::YELLOW:
		return "Yellow";
		break;
	case Colour::BLUE:
		return "Blue";
		break;
	case Colour::GREEN:
		return "Green";
		break;
	case Colour::WHITE:
		return "White";
		break;
	default:
		return "Invalid colour!";
		break;
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
