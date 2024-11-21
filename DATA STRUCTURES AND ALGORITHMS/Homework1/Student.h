#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H

//#include "Time.h"
#include "Seat.h"
#include <string>
#include <iostream>

class Student {
private:
    unsigned int id;
    unsigned int course;
    unsigned int arrivalTime;
    unsigned int duration;
    Seat *seat;
    bool hasSeat;

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
    bool getHasSeat() const;

    void setID(unsigned int id);
    void setCourse(unsigned int course);
    void setDuration(unsigned int duration);
    void setHasSeat(bool flag);

    void occupySeat(Seat *seat);
    void printInformation() const;
};

#endif //DSA_STUDENT_H
