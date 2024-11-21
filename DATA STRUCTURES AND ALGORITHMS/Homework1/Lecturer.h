#ifndef DSA_LECTURER_H
#define DSA_LECTURER_H

#include <stack>

class Lecturer {
private:
    unsigned int arriveTime, checkTime;
    std::stack<unsigned int> studentsWorks, checkedWorks;

public:
    Lecturer(unsigned int arriveTime, unsigned int checkTime);
    Lecturer() = delete;
    Lecturer(const Lecturer &other) = delete;
    Lecturer &operator=(const Lecturer &other) = delete;
    ~Lecturer() = default;

    unsigned int getArriveTime() const;
    unsigned int getCheckTime() const;
    const std::stack<unsigned int> &getStudentsWorks() const;
    const std::stack<unsigned int> &getCheckedWorks() const;

    void setArriveTime(unsigned int time);
    void setCheckTime(unsigned int time);

    void receiveStudentWork(unsigned int studentID);
    void checkWorks(unsigned int &currentTime);
    void printCheckedWorks();
};


#endif //DSA_LECTURER_H
