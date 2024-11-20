#include "Student.h"
#include <iostream>
#include <string>
#include <cassert>

Student::Student(const std::string &firstName, const std::string &familyName, const std::string &arriveTime, const std::string &departureTime, short grade)
        : arriveTime(Time::fromString(arriveTime)), departureTime(Time::fromString(departureTime)) {
    this->setFirstName(firstName);
    this->setFamilyName(familyName);
    this->setArriveTime(this->arriveTime, this->departureTime);
    increaseID();
    this->setGrade(grade);
}

const std::string Student::getFirstName() const {
    return this->firstName;
}

const std::string Student::getFamilyName() const {
    return this->familyName;
}

const std::string Student::getCourse() const {
    return this->course;
}

const int Student::getID() {
    return id;
}

bool Student::getHasSeat() const {
    return this->getHasSeat();
}

short Student::getGrade() const {
    return this->grade;
}

short Student::getDuration() const {
    return this->duration;
}

void Student::setFirstName(const std::string &name) {
    this->firstName = correctName(name);
}

void Student::setFamilyName(const std::string &name) {
    this->familyName = correctName(name);
}

void Student::setArriveTime(Time arriveTime, Time departureTime) {
    if (this->arriveTime.getHour() > this->departureTime.getHour())
        throw std::invalid_argument("Invalid arrival time given.");
}

void Student::setHasSeat(bool flag) {
    this->hasSeat = flag;
}

void Student::setGrade(short grade) {
    assert(2 <= grade && grade <= 4);
    this->grade = grade;
}

void Student::setDuration(short duration) {
    assert(duration <= 120); //2 hours in minutes
    this->duration = duration;
}

void Student::printInformation() const {
    std::cout << "------- INFORMATION FOR STUDENT: " << id << " -------\n";
    std::cout << "Names: " << this->firstName << ' ' << this->familyName << '\n';
    std::cout << "Course: " << this->course << ", grade: " << this->grade << '\n';

    std::cout << "Arrival time: ";
    this->arriveTime.printTime();
    std::cout << "Departure time: ";
    this->departureTime.printTime();
    std::cout << '\n';

    std::cout << "Has seat: " << (this->hasSeat ? "yes" : "no") << " ";
    if(this->hasSeat)
        seat.printSeat();

    std::cout << "Needed time in minutes for the exam: " << this->duration << '\n';
    std::cout << '\n';
}

//void Student::occupySeat()  {
//    Seat seat;
//
//    try {
//        seat.setSeat();
//        this->setHasSeat(true);
//        seat.setIfOccupied(true);
//    } catch (std::runtime_error &e) {
//        std::cerr << "Error while setting a seat for student: " << this->getID() << '\n';
//        e.what();
//    }
//}

int main() {
    try {
        Student student1("Ivan", "Ivanov", "08:30", "17:00", 2);
        student1.printInformation();
//        student1.occupySeat();
//
////        Student student2 = student1;
//
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}