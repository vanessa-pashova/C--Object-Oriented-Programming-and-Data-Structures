#include "Seat.h"

Seat::Seat(unsigned int row, unsigned int column, bool broken, bool occupied) {
    this->setRow(row);
    this->setColumn(column);
    this->setIfBroken(broken);
    this->setIfOccupied(occupied);
}

bool &Seat::operator==(const Seat &other) const {
    bool flag = false;

    if(this->row == other.row && this->column == other.column)
        flag = true;

    return flag;
}

bool Seat::getBroken() const {
    return this->broken;
}

bool Seat::getOccupied() const {
    return this->occupied;
}

unsigned int Seat::getRow() const {
    return this->row;
}

unsigned int Seat::getColumn() const {
    return this->column;
}

void Seat::setIfBroken(bool flag) {
    this->broken = flag;
}

void Seat::setIfOccupied(bool flag) {
    this->occupied = flag;
}

void Seat::setRow(unsigned int row) {
    if(1 <= row && row <= 6)
        this->row = row;

    else
        throw std::invalid_argument("Invalid number of the row.");
}

void Seat::setColumn(unsigned int column) {
    if(1 <= column && column <= 7)
        this->column = column;

    else
        throw std::invalid_argument("Invalid number of column.");
}

void Seat::printSeat() const {
    std::cout << "R: " << this->row << ", C: " << this->column << '\n';
}
