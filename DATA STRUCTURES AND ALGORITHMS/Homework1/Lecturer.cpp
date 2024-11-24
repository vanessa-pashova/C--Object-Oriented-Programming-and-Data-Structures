#include "Lecturer.h"
#include <iostream>

const unsigned int CHECK_TIME = 50;
const unsigned int ARRIVAL_TIME = 60;

Lecturer::Lecturer(unsigned int arriveTime, unsigned int checkTime) {
    this->setArriveTime(arriveTime);
    this->setCheckTime(checkTime);
}

unsigned int Lecturer::getArriveTime() const {
    return this->arriveTime;
}

unsigned int Lecturer::getCheckTime() const {
    return this->checkTime;
}

const std::stack<unsigned int> &Lecturer::getStudentsWorks() const {
    return this->studentsWorks;
}

const std::stack<unsigned int> &Lecturer::getCheckedWorks() const {
    return this->checkedWorks;
}

void Lecturer::setArriveTime(unsigned int time) {
//    if(ARRIVAL_TIME < time)
//        throw std::logic_error("Lecturer comes too late, next time better calculate his time, pls.");
//
//    else
        this->arriveTime = time;
}

void Lecturer::setCheckTime(unsigned int time) {
//    if(CHECK_TIME < time)
//        throw std::logic_error("Takes too long for the lecturer to check a work.");
//
//    else
        this->checkTime = time;
}

void Lecturer::receiveStudentWork(unsigned int studentID) {
    if(1 <= studentID && studentID <= 256)
        this->studentsWorks.push(studentID);

    else
        throw std::invalid_argument("Invalid student ID.");
}

void Lecturer::checkWorks(unsigned int &currentTime) {
    while(!this->studentsWorks.empty()) {
        unsigned int currentWork = this->studentsWorks.top();
        studentsWorks.pop();
        this->checkedWorks.push(currentWork);

        currentTime += this->checkTime;
    }
}

void Lecturer::printCheckedWorks() {
    std::cout << "------ PRINT CHECKED WORKS ------\n";

    while(!this->checkedWorks.empty()) {
        std::cout << this->checkedWorks.top() << '\n';
        this->checkedWorks.pop();
    }
}