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

unsigned int Hall::getStartTime() const {
    return this->startTime;
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

void Hall::setStartTime() {
    this->startTime = 480; //8 am in minutes;
}

void Hall::insertValuesForRowAndCols(unsigned int rows, unsigned int columns) {
    this->row = rows;
    this->column = columns;

    if(50 < this->row * this->column )
        throw std::invalid_argument("Invalid dimensions of the Hall.");
}

void Hall::defineBrokenSeats(std::vector<unsigned int> brokenSeatsIndexes) {
    for (unsigned int index : brokenSeatsIndexes) {
        if (index >= row * column)
            throw std::invalid_argument("Invalid seat index.");

        Seat* seat = new Seat(index, true, false, 0);
        brokenSeats.push_back(seat);
    }
}

void Hall::generateAvailableSeats(std::vector<unsigned int> brokenSeatsIndexes) {
    defineBrokenSeats(brokenSeatsIndexes);

    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            unsigned int index = i * column + j;

            bool isBroken = false;
            for (Seat* brokenSeat : brokenSeats) {
                if (brokenSeat->getIndex() == index) {
                    isBroken = true;
                    break;
                }
            }

            if (isBroken)
                continue;

            if ((i % 2 == 0) && (j % 2 == 0)) {
                Seat* seat = new Seat(index, false, false, 0);
                matrixOfSeats.push_back(seat);
            }
        }
    }
}

bool Hall::assignSeatToStudent(unsigned int studentID, unsigned int arrivalTime, unsigned int duration) {
    for (Seat* seat : matrixOfSeats) {
        if (!seat->getOccupied() || seat->getOccupiedUntilTime() <= arrivalTime) {
            seat->setIfOccupied(true);

            unsigned int releaseTime = arrivalTime + duration;
            seat->setOccupiedUntilTime(releaseTime);

//            std::cout << "Student " << studentID << " assigned to seat " << seat->getIndex() << " until time " << formatTime(releaseTime) << ".\n";
            return true;
        }
    }

//    std::cout << "No available seat for student " << studentID << " at time " << formatTime(arrivalTime) << ".\n";
    return false;
}

void Hall::releaseSeats(unsigned int currentTime) {
    for (Seat* seat : matrixOfSeats) {
        if (seat->getOccupied() && seat->getOccupiedUntilTime() <= currentTime) {
            unsigned int releaseTime = seat->getOccupiedUntilTime(); // Вземаме времето за освобождаване
            seat->setIfOccupied(false); // Освобождаваме мястото
//            std::cout << "Seat at index " << seat->getIndex() << " is now free at time " << formatTime(releaseTime) << ".\n";
        }
    }
}

void Hall::printLayoutOfHall() const {
    std::cout << "------- HALL LAYOUT -------\n";
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            unsigned int index = i * column + j;

            char sign = 'F';

            for (Seat* brokenSeat : brokenSeats) {
                if (brokenSeat->getIndex() == index) {
                    sign = 'B';
                    break;
                }
            }

            if (sign == 'F') {
                if (i % 2 == 0 && j % 2 == 0)
                    sign = 'O';
            }

            std::cout << sign;
        }

        std::cout << '\n';
    }
}

bool Hall::hasFreeSeats() const {
    for (Seat* seat : matrixOfSeats) {
        if (!seat->getOccupied())
            return true;
    }

    return false;
}