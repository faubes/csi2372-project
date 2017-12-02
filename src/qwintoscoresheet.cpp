#include "qwintoscoresheet.h"
#include <iostream>

QwintoScoreSheet::QwintoScoreSheet(const std::string& n) : ScoreSheet(n) {}

bool QwintoScoreSheet::col_complete(int col) {
    return ((redRow[col] > 0) && (yellowRow[col] > 0) && (blueRow[col] > 0));
}

int QwintoScoreSheet::calcTotal() {
    int newScore = 0;

    //filled row stuff
    if (redRow.isFull()) {
        //get most right
        newScore += redRow[11];
    } else {
        //return the count itself
        newScore += redRow.row_complete();
    }

    if(yellowRow.isFull()) {
        //get most right
        newScore += yellowRow[10];
    } else {
        //return the count itself
        newScore += yellowRow.row_complete();
    }

    if (blueRow.isFull()) {
        //get most right
        newScore += blueRow[9];
    } else {
        //return the count itself
        newScore += blueRow.row_complete();
    }

    //bonus points (the % cells)
    //col 2
    if (col_complete(2)) {
        newScore += blueRow[2];
    }
    //col 3
    if (col_complete(3)) {
        newScore += redRow[3];
    }
    //col 7
    if (col_complete(7)) {
        newScore += redRow[7];
    }
    //col 8
    if (col_complete(8)) {
        newScore += yellowRow[8];
    }
    //col 9
    if (col_complete(9)) {
        newScore += blueRow[9];
    }

    //failed throws
    newScore = newScore - (5 * getFailedThrows());

    return newScore;
}

bool QwintoScoreSheet::validateCol(RollOfDice roll, Colour c, int position) {
    bool valid = true;
    std::vector<int> values;
    switch(c) {
    case(Colour::RED):
        // filter out zeroes and negatives
        values.emplace_back(static_cast<int>(roll));

        if (yellowRow[position] > 0) {
            values.emplace_back(yellowRow[position]);
        }

        if (blueRow[position] > 0) {
            values.emplace_back(blueRow[position]);
        }
        break;
    case(Colour::YELLOW):
        // filter out zeroes and negatives
        if (redRow[position] > 0) {
            values.emplace_back(redRow[position]);
        }

        values.emplace_back(static_cast<int>(roll));

        if (blueRow[position] > 0) {
            values.emplace_back(blueRow[position]);
        }
        break;
    case(Colour::BLUE):
        // filter out zeroes and negatives
        if (redRow[position] > 0) {
            values.emplace_back(redRow[position]);
        }

        if (yellowRow[position] > 0) {
            values.emplace_back(yellowRow[position]);
        }

        values.emplace_back(static_cast<int>(roll));
        break;
    default:
        std::cout << "Error" << std::endl;
        break;
    }

    // sort copied values so we can compare only neighbours for uniqueness
    sort(values.begin(), values.end());

    for (int j = 0; j < values.size() - 1; j++) {
        if (values[j] == values[j + 1]) {
            valid = false;
        }

    }
    return valid;
}

// output contents of row to ostream
void QwintoScoreSheet::print(std::ostream& os) const {
    std::stringstream output;
    output << redRow;
    output << yellowRow;
    output << blueRow;
    os << output.str();
    os << "Failed throws: " << getFailedThrows() << std::endl;
}

// returns true if this scoresheet has reached gameover state
bool QwintoScoreSheet::operator!() const {
    int completerows = 0;
    if (this->redRow.isFull()) completerows++;
    if (this->yellowRow.isFull()) completerows++;
    if (this->blueRow.isFull()) completerows++;
    return ((completerows > 1) || (this->getFailedThrows() == 4));
}

bool QwintoScoreSheet::score(RollOfDice roll, Colour c, int position) {
    //call the QwintoRow validate to check if a) the cell is valid b) the new value is valid in a row context
    bool valid_row;
    bool valid_col;
    int row;

    switch(c) {
    case(Colour::RED):
        valid_row = redRow.validateRow(roll, position);
        break;
    case(Colour::YELLOW):
        valid_row = yellowRow.validateRow(roll, position);
        break;
    case(Colour::BLUE):
        valid_row = blueRow.validateRow(roll, position);
        break;
    default:
        std::cout << "Error" << std::endl;
        break;
    }

    //this is column check. all values in column must be unique
    valid_col = validateCol(roll, c, position);

    if ((valid_row == true) && (valid_col == true)) {
        //then we make insertion
        switch(c) {
        case(Colour::RED):
            redRow[position] = roll;
            break;
        case(Colour::YELLOW):
            yellowRow[position] = roll;
            break;
        case(Colour::BLUE):
            blueRow[position] = roll;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
        }
    }

    return ((valid_row == true) && (valid_col == true));
}

// Lazy way to test if there is a valid place to enter a score
// creates a copy of scoresheet and tests all possible locations
// until a valid one is found
std::vector<Colour> QwintoScoreSheet::getAvailableRows(const RollOfDice& rod) const {
    std::vector<Colour> availableRows;
    QwintoScoreSheet copy(*this);
    for (const auto& d : rod) {
		bool valid = false;
        for (int i = 0; i < 12; i++) {
            valid = copy.score(rod, d.getColour(), i);
            if (valid) {
				availableRows.emplace_back(d.getColour());
				break;
			}
        }
    }
    return availableRows;
}

// Returns true if all entries of a row are filled
bool QwintoScoreSheet::isRowFull(const Colour& c) const {
    switch(c) {
    case(Colour::RED):
        return this->redRow.isFull();
        break;
    case(Colour::YELLOW):
        return this->yellowRow.isFull();
        break;
    case(Colour::BLUE):
        return this->blueRow.isFull();
        break;
    }
}

bool QwintoScoreSheet::rowContains(const Colour& c, const RollOfDice & rod) const {
    bool contains = false;
    switch(c) {
    case(Colour::RED):
        contains = redRow.contains(rod);
        break;
    case(Colour::YELLOW):
        contains = yellowRow.contains(rod);
        break;
    case(Colour::BLUE):
        contains = blueRow.contains(rod);
        break;
    default:
        std::cerr << "QwintoScoreSheet::rowContains invoked with bad colour" << std::endl;
        break;
    }
    return contains;
}
