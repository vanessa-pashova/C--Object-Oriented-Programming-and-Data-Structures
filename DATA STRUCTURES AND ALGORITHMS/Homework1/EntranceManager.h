#ifndef C_PROGRAMMING_ENTRANCEMANAGER_H
#define C_PROGRAMMING_ENTRANCEMANAGER_H

#include <fstream>
#include <iostream>
#include <queue>

#include "Hall.h"
#include "Student.h"
#include "StudentComparator.cpp"

class EntranceManager {
private:
    Hall *hall;

    unsigned int rows, columns, lecturerArrive, lecturerTimeToCheck, brokenSeatsCount;
    std::priority_queue<Student*, std::vector<Student*>, CompareStudentsCourses> queue;
    std::vector<Student*> studentsWhoHasFinished;

    void loadFile(std::ifstream &filename) {
        filename >> rows >> columns >> lecturerArrive >> lecturerTimeToCheck >> brokenSeatsCount;

        hall = new Hall(rows, columns);
        hall->insertValuesForRowAndCols(rows, columns);
        hall->setBrokenSeatsCount(brokenSeatsCount);

        std::vector<unsigned int> brokenSeatsIndexes(brokenSeatsCount);
        for(std::size_t i = 0; i < brokenSeatsCount; i++)
            filename >> brokenSeatsIndexes[i];

        hall->defineBrokenSeats(brokenSeatsIndexes);
        hall->generateAvailableSeats(brokenSeatsIndexes);
    }

    void loadStudentsFromFile(std::ifstream &filename) {
        std::string command;
        while(filename >> command) {
            if(command == "end")
                break;

            if(command == "enter") {
                unsigned int t = 0, F = 0, T = 0, K = 0;
                filename >> t >> F >> T >> K;

                queue.push(new Student(t, F, T, K));
            }
        }
    }

    void cleanQueue() {
        while(!queue.empty()) {
            delete queue.top();
            queue.pop();
        }
    }

    void cleanStudentsWhoFinished() {
        for(Student *student : this->studentsWhoHasFinished)
            delete student;

        studentsWhoHasFinished.clear();
    }

public:
    EntranceManager(const std::string &filename);
    ~EntranceManager();

    void execution();
    void printOutcome() const;
};


#endif //C_PROGRAMMING_ENTRANCEMANAGER_H