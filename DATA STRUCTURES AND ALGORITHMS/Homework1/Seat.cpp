#include "Seat.h"

Seat::Seat(unsigned int index, bool broken, bool occupied) : occupiedUntilTime(0) {
    this->setIndex(index);
    this->setIfBroken(broken);
    this->setIfOccupied(occupied);
}

Seat::Seat() : index(0), broken(false), occupied(false), occupiedUntilTime(0) {}

Seat &Seat::operator=(const Seat &other) {
    if(this != &other) {
        this->index = other.index;
        this->broken = other.broken;
        this->occupied = other.occupied;
        this->occupiedUntilTime = other.occupiedUntilTime;
    }

    return *this;
}

bool Seat::operator==(const Seat &other) const {
    bool flag = false;

    if(this->index == other.index && this->occupied == other.occupied
       && this->broken == other.broken && this->occupiedUntilTime == other.occupiedUntilTime)
        flag = true;

    return flag;
}

bool Seat::getBroken() const {
    return this->broken;
}

bool Seat::getOccupied() const {
    return this->occupied;
}

unsigned int Seat::getIndex() const {
    return this->index;
}

char Seat::getSign() const {
    if(this->broken)
        return 'B';

    if(this->occupied)
        return 'O';

    return 'F';
}

unsigned int Seat::getOccupiedUntilTime() const {
    return this->occupiedUntilTime;
}

void Seat::setIfBroken(bool flag) {
    this->broken = flag;
}

void Seat::setIfOccupied(bool flag) {
    this->occupied = flag;
}

void Seat::setIndex(unsigned int index) {
    if(0 <= index && index <= 256)
        this->index = index;

    else
        throw std::invalid_argument("Index out of bound given.");
}

void Seat::setOccupiedUntilTime(unsigned int time) {
    this->occupiedUntilTime = time;
}

void Seat::printSeat() const {
    std::cout << "Index of the seat: " << this->index << '\n';
}