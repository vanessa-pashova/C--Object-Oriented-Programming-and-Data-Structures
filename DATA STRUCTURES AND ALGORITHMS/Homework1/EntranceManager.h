#ifndef C_PROGRAMMING_ENTRANCEMANAGER_H
#define C_PROGRAMMING_ENTRANCEMANAGER_H

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "Hall.h"
#include "Student.h"
#include "Lecturer.h"

class EntranceManager {
private:
    Hall* hall;
    Lecturer* lecturer;

    unsigned int rows, columns, lecturerArrive, lecturerTimeToCheck, brokenSeatsCount;
    unsigned int currentTime;
    std::queue<Student*> waitingQueue;
    std::vector<Student*> studentsInHall;
    std::vector<Student*> studentsWhoFinished;

    void loadFile(std::ifstream& filename) {
        filename >> rows >> columns >> lecturerArrive >> lecturerTimeToCheck >> brokenSeatsCount;

        hall = new Hall(rows, columns);
        lecturer = new Lecturer(lecturerArrive + currentTime, lecturerTimeToCheck);

        hall->setBrokenSeatsCount(brokenSeatsCount);

        std::vector<unsigned int> brokenSeatsIndexes(brokenSeatsCount);
        for (std::size_t i = 0; i < brokenSeatsCount; ++i)
            filename >> brokenSeatsIndexes[i];

        hall->defineBrokenSeats(brokenSeatsIndexes);
        hall->generateAvailableSeats(brokenSeatsIndexes);
    }

    void loadStudentsFromFile(std::ifstream& filename) {
        std::string command;
        while (filename >> command) {
            if (command == "end")
                break;

            if (command == "enter") {
                unsigned int t, F, T, K;
                filename >> t >> F >> T >> K;
                waitingQueue.push(new Student(t, F, T, K));
            }
        }
    }

    void cleanStudents(std::queue<Student*>& queue) {
        while (!queue.empty()) {
            delete queue.front();
            queue.pop();
        }
    }

    void cleanStudents(std::vector<Student*>& students) {
        for (Student* student : students)
            delete student;

        students.clear();
    }

    void prioritizeWaitingQueue() {
        std::vector<Student*> temp;
        while (!waitingQueue.empty()) {
            temp.push_back(waitingQueue.front());
            waitingQueue.pop();
        }

        for (std::size_t i = 0; i < temp.size(); ++i) {
            for (std::size_t j = 0; j < temp.size() - i - 1; ++j) {
                Student* s1 = temp[j];
                Student* s2 = temp[j + 1];

                bool shouldSwap = false;

                if (s1->getCourse() != 2 && s2->getCourse() == 2)
                    shouldSwap = true;

                else if (s1->getCourse() == s2->getCourse() && s1->getArrivalTime() > s2->getArrivalTime())
                    shouldSwap = true;

                if (shouldSwap)
                    std::swap(temp[j], temp[j + 1]);
            }
        }

        for (Student* student : temp)
            waitingQueue.push(student);
    }

public:
    EntranceManager(const std::string& filename);
    ~EntranceManager();

    void execution();
    void printOutcome() const;
};

#endif //C_PROGRAMMING_ENTRANCEMANAGER_H
