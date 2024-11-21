#include "EntranceManager.h"

EntranceManager::EntranceManager(const std::string &filename) {
    std::ifstream file(filename);

    if(!file.is_open())
        throw std::runtime_error("Cannot open file.");

    this->loadFile(file);
    this->loadStudentsFromFile(file);

    file.close();
}

EntranceManager::~EntranceManager() {
    delete this->hall;
    this->cleanQueue();
    this->cleanStudentsWhoFinished();
}

void EntranceManager::execution() {
    unsigned int currentTime = 0;

    while (!queue.empty()) {
        Student* student = queue.top();

        if (student->getArrivalTime() > currentTime)
            currentTime = student->getArrivalTime();

        queue.pop();

        if (hall->assignSeatToStudent(student->getID(), student->getArrivalTime(), student->getDuration()))
            studentsWhoHasFinished.push_back(student);

        else
            queue.push(student);

        hall->releaseSeats(currentTime);
        currentTime++;
    }
}

void EntranceManager::printOutcome() const {
    this->hall->printLayoutOfHall();

    std::cout << "------- STUDENTS WHO HAS FINISHED -------\n";
    for(const Student *student : studentsWhoHasFinished)
        student->printInformation();
}