#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H

#include "Seat.h"
#include <string>
#include <iostream>

class Student {
private:
    unsigned int id, course, arrivalTime, duration, finishTime;
    bool hasSeat;
    Seat *seat;

public:
    Student(unsigned int arrivalTime, unsigned int id, unsigned int duration, unsigned int course);
    Student() = delete;

    Student(const Student& other) = delete;
    Student &operator=(const Student &other) = delete;

    ~Student();

    unsigned int getArrivalTime() const;
    unsigned int getID() const;
    unsigned int getDuration() const;
    unsigned int getCourse() const;
    unsigned int getFinishTime() const;
    bool getHasSeat() const;

    Seat *getSeat() const;

    void setID(unsigned int id);
    void setCourse(unsigned int course);
    void setDuration(unsigned int duration);
    void setHasSeat(bool flag);

    void calculateFinishTime();

    void occupySeat(Seat *seat);
    void realeaseSeat(Seat *seat);
    void printInformation() const;
};

#endif //DSA_STUDENT_H