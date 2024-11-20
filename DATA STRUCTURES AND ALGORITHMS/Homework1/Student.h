#ifndef DSA_STUDENT_H
#define DSA_STUDENT_H

#include "Time.h"
#include "Seat.h"
#include <string>
#include <iostream>

class Student {
private:
    std::string firstName, familyName;
    const std::string course = "KN2";
    static inline int id = 0;
    short grade;

    Time arriveTime, departureTime;
    short duration;

    bool hasSeat;
    Seat seat; //may cause problems

    static void increaseID() {
        if(0 <= id && id <= 256)
            id++;
    }

    std::string correctName(const std::string &name) {
        char firstLetter = std::toupper(name[0]);
        std::string substr = name.substr(1, name.length() - 1);

        for(int i = 0; i < substr.length(); i++)
            std::tolower(substr[i]);


        return (firstLetter + substr);
    }

public:
    Student(const std::string &firstName, const std::string &familyName, const std::string &arrivalTime, const std::string &departureTime, short grade);
    Student() = delete; //prevents from creating a def obj
    Student(const Student &other) = delete; //prevents from duplicating an obj as they must be unique
    Student &operator=(const Student &other) = delete;
    ~Student() = default;

    const std::string getFirstName() const;
    const std::string getFamilyName() const;
    const std::string getCourse() const;
    static const int getID();
    bool getHasSeat() const;
    short getGrade() const;
    short getDuration() const;

    void setFirstName(const std::string &name);
    void setFamilyName(const std::string &name);
    void setArriveTime(Time arriveTime, Time departureTime);
    void setHasSeat(bool flag);
    void setGrade(short grade);
    void setDuration(short duration);

    void printInformation() const;

    void occupySeat();
};

#endif //DSA_STUDENT_H
