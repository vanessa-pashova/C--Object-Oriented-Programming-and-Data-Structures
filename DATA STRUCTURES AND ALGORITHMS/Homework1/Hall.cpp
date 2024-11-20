#include "Hall.h"
#include <cassert>

Hall::~Hall() {
    for (Seat* seat : brokenSeats)
        delete seat;

    brokenSeats.clear();

    for (Seat* seat : matrixOfSeats)
        delete seat;

    matrixOfSeats.clear();
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

const std::vector<Seat*>& Hall::getBrokenSeats() const {
    return this->brokenSeats;
}

void Hall::setBrokenSeatsCount(unsigned int brokenSeatsCnt) {
    if(this->row * this->column < brokenSeatsCnt)
        throw std::invalid_argument("Invalid number of broken seats: much more than the Hall capacity.");

    else
        this->brokenSeatsCount = brokenSeatsCnt;
}

void Hall::insertValuesForRowAndCols() {
    unsigned int rows = 0, columns = 0;
    std::cout << "> Insert the number of the rows: ";
    std::cin >> rows;
    std::cout << "> Insert the number of the columns: ";
    std::cin >> columns;

    this->row = rows;
    this->column = columns;
}

void Hall::defineBrokenSeats() {
    unsigned int brokenSeatsCnt;
    std::cout << "> Insert the number of the broken seats: ";
    std::cin >> brokenSeatsCnt;

    this->setBrokenSeatsCount(brokenSeatsCnt);
    this->brokenSeats.resize(this->brokenSeatsCount);

    std::cout << "-------- Broken Seats Insertion --------\n";
    for(Seat *seat : brokenSeats) {
        unsigned int row = 0, col = 0;

        std::cout << "> Insert the number of the row: ";
        std::cin >> row;
        assert(row < this->row);
        std::cout << "> Insert the number of the column: ";
        std::cin >> col;
        assert(col < this->column);

        seat->setRow(row);
        seat->setColumn(col);
        seat->setIfBroken(true);
        seat->setIfOccupied(false);

        std::cout << '\n';
    }
}

//must add the queue with students so we know who where sits and till when
//because we need to know which seat is free then
void Hall::generateAvailableSeats() {
    std::cout << "-------- Seats Insertion --------\n";

    for (std::size_t i = 0; i < this->row; i++) {
        for (std::size_t j = 0; j < this->column; j++) {
            if ((i % 2 != 0) && (j % 2 != 0)) {
                Seat *seat = new Seat(static_cast<unsigned int>(i + 1), static_cast<unsigned int>(j + 1), false, true);

                bool isBroken = false;
                for (Seat *brokenSeat : brokenSeats) {
                    if (*brokenSeat == *seat) {
                        isBroken = true;
                        break;
                    }
                }

                if (!isBroken)
                    this->matrixOfSeats.emplace_back(seat);

                else
                    delete seat;
            }
        }
    }
}