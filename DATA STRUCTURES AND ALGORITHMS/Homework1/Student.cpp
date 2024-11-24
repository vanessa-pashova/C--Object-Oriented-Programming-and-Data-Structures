#include "Student.h"
#include <iostream>
#include <string>
#include <cassert>

const unsigned int MIN_DURATION = 15;
const unsigned int MAX_DURATION = 120;

Student::Student(unsigned int arrivalTime, unsigned int id, unsigned int duration, unsigned int course) {
    this->arrivalTime = arrivalTime;
    this->setID(id);
    this->setDuration(duration);
    this->setCourse(course);
}

Student::~Student() {
    if (this->seat != nullptr) {
        delete seat;
        seat = nullptr;
    }
}

unsigned int Student::getArrivalTime() const {
    return this->arrivalTime;
}

unsigned int Student::getID() const {
    return this->id;
}

unsigned int Student::getDuration() const {
    return this->duration;
}

unsigned int Student::getCourse() const {
    return this->course;
}

unsigned int Student::getFinishTime() const {
    return this->finishTime;
}

bool Student::getHasSeat() const {
    return this->hasSeat;
}

Seat *Student::getSeat() const {
    return this->seat;
}

void Student::setID(unsigned int id) {
    if(1 <= id && id <= 256)
        this->id = id;

    else
        throw std::invalid_argument("Invalid studentID given.");
}

void Student::setDuration(unsigned int duration) {
    if(MAX_DURATION < duration)
        throw std::logic_error("Student puts too much effort.");

    else if(duration < MIN_DURATION)
        throw std::logic_error("Student does not give... this exam a shot.");

    else
        this->duration = duration;
}

void Student::setCourse(unsigned int course) {
    if (2 <= course && course <= 4)
        this->course = course;

    else
        throw std::logic_error("Invalid course given.");
}

void Student::setHasSeat(bool flag) {
    this->hasSeat = flag;
}

void Student::calculateFinishTime() {
    this->finishTime = this->arrivalTime + this->duration;
}

void Student::occupySeat(Seat *seat) {
    if(!seat->getBroken() || !seat->getOccupied()) {
        this->seat = seat;
        this->setHasSeat(true);

        seat->setIfOccupied(true);
        seat->setOccupiedUntilTime(this->duration);
    }

    else
        throw std::invalid_argument("This seat is broken or taken.");
}

void Student::realeaseSeat(Seat *seat) {
    this->setHasSeat(false);

    seat->setIfOccupied(false);
}

void Student::printInformation() const {
    std::cout << this->id << '\n';
}