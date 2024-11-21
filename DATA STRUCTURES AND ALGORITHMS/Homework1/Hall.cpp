#include "Hall.h"
#include <cassert>

Hall::Hall(unsigned int row, unsigned int column)
        : row(row), column(column), brokenSeatsCount(0) {}

Hall::~Hall() {
    clearSeats(matrixOfSeats);
    clearSeats(brokenSeats);
}

unsigned int Hall::getRowsInHall() const {
    return this->row;
}

unsigned int Hall::getColumnsInHall() const {
    return this->column;
}

unsigned int Hall::getBrokenSeatsCount() const {
    return this->brokenSeatsCount;
}

const std::vector<Seat*> &Hall::getBrokenSeats() const {
    return this->brokenSeats;
}

const std::vector<Seat*> &Hall::getMatrixOfSeats() const {
    return this->matrixOfSeats;
}

void Hall::setBrokenSeatsCount(unsigned int brokenSeatsCnt) {
    if((this->row * this->column) < brokenSeatsCnt)
        throw std::invalid_argument("Invalid number of broken seats: much more than the Hall capacity.");

    else
        this->brokenSeatsCount = brokenSeatsCnt;
}

void Hall::insertValuesForRowAndCols(unsigned int rows, unsigned int columns) {
    this->row = rows;
    this->column = columns;
}

//must receive a vector with the indexes of the broken chairs, create obj of Seat type and initialize them
void Hall::defineBrokenSeats(std::vector<unsigned int> brokenSeatsIndexes) {
    for (unsigned int index : brokenSeatsIndexes) {
        if (index >= row * column)
            throw std::invalid_argument("Invalid seat index.");

        Seat* seat = new Seat(index, true, false);
        brokenSeats.push_back(seat);
    }
}

//receives a vector with the broken seats indexes, creates a seat with the current index and if its equal to some seat from brokenSeatsIndexes
//‼️ CHANGED ‼️
void Hall::generateAvailableSeats(std::vector<unsigned int> brokenSeatsIndexes) {
    defineBrokenSeats(brokenSeatsIndexes); // Определяме счупените седалки

    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            unsigned int index = i * column + j;

            // Пропускаме счупените седалки
            bool isBroken = false;
            for (Seat* brokenSeat : brokenSeats) {
                if (brokenSeat->getIndex() == index) {
                    isBroken = true;
                    break;
                }
            }
            if (isBroken) continue;

            // Запазваме свободни седалки на "през ред и място"
            if ((i % 2 == 0) && (j % 2 == 0)) {
                Seat* seat = new Seat(index, false, false);
                matrixOfSeats.push_back(seat);
            }
        }
    }
}

void Hall::printLayoutOfHall() const {
    std::cout << "------- HALL LAYOUT -------\n";
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            unsigned int index = i * column + j;
            char sign = 'F'; //by default

            for (Seat* brokenSeat : brokenSeats) {
                if (brokenSeat->getIndex() == index) {
                    sign = 'B';
                    break;
                }
            }

            for (Seat* seat : matrixOfSeats) {
                if (seat->getIndex() == index && seat->getOccupied()) {
                    sign = 'O';
                    break;
                }
            }

            std::cout << sign;
        }

        std::cout << '\n';
    }
}

bool Hall::assignSeatToStudent(unsigned int studentID) {
    for (Seat* seat : matrixOfSeats) {
        if (!seat->getOccupied()) { // ✨ Намираме първата свободна седалка
            seat->setIfOccupied(true);
            return true; // Успешно зададена седалка
        }
    }
    return false; // Няма свободна седалка
}

void Hall::releaseSeats(unsigned int currentTime) {
    for (Seat* seat : matrixOfSeats) {
        if (seat->getOccupied() && seat->getOccupiedUntilTime() <= currentTime) {
            seat->setIfOccupied(false); // Освобождаваме седалката
            std::cout << "Seat at index " << seat->getIndex() << " is now free.\n";
        }
    }
}