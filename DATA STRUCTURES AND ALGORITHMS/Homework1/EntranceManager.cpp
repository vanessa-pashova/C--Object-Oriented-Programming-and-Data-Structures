#include "EntranceManager.h"

EntranceManager::EntranceManager(const std::string& filename)
        : hall(nullptr), lecturer(nullptr), currentTime(480) { // 8:00 am
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Cannot open file.");

    this->loadFile(file);
    this->loadStudentsFromFile(file);
    file.close();
}

EntranceManager::~EntranceManager() {
    delete hall;
    delete lecturer;
    cleanStudents(waitingQueue);
    cleanStudents(studentsInHall);
    cleanStudents(studentsWhoFinished);
}

void EntranceManager::execution() {
    const unsigned int startTime = 480; // 8:00 AM
    currentTime = startTime;

    while (!waitingQueue.empty() || !studentsInHall.empty()) {
        while (hall->hasFreeSeats() && !waitingQueue.empty()) {
            Student* student = waitingQueue.front();
            unsigned int studentArrival = startTime + student->getArrivalTime();

            if (studentArrival <= currentTime) {
                waitingQueue.pop();

                if (hall->assignSeatToStudent(student->getID(), studentArrival, student->getDuration()))
                    studentsInHall.push_back(student);
            }

            else
                break;
        }

        hall->releaseSeats(currentTime);

        if (currentTime >= lecturer->getArriveTime()) {
            for (size_t i = 0; i < studentsInHall.size(); ++i) {
                for (size_t j = 0; j < studentsInHall.size() - i - 1; ++j) {
                    unsigned int finishTime1 = startTime + studentsInHall[j]->getArrivalTime() + studentsInHall[j]->getDuration();
                    unsigned int finishTime2 = startTime + studentsInHall[j + 1]->getArrivalTime() + studentsInHall[j + 1]->getDuration();

                    if (finishTime1 > finishTime2)
                        std::swap(studentsInHall[j], studentsInHall[j + 1]);
                }
            }

            while (!studentsInHall.empty()) {
                Student* student = studentsInHall.front();
                studentsInHall.erase(studentsInHall.begin());

                lecturer->receiveStudentWork(student->getID());
                studentsWhoFinished.push_back(student);
            }

            lecturer->checkWorks(currentTime);
        }

        ++currentTime;
    }
}

void EntranceManager::printOutcome() const {
    hall->printLayoutOfHall();
    lecturer->printCheckedWorks();

//    std::cout << "------- STUDENTS WHO HAS FINISHED -------\n";
//    for (const Student* student : studentsWhoFinished)
//        student->printInformation();

    unsigned int hours = currentTime / 60;
    unsigned int minutes = currentTime % 60;
    std::cout << "Finish time: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << '\n';
}
