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
    while(!this->queue.empty()) {
        Student *student = this->queue.top();
        this->queue.pop();

        if(hall->assignSeatToStudent(student->getID()))
            this->studentsWhoHasFinished.push_back(student);

        //✨ not sure if this works properly
        else {
            std::cerr << "No available seat for student: " << student->getID() << '\n';
            delete student;
        }
    }
}

void EntranceManager::printOutcome() const {
    this->hall->printLayoutOfHall();

    std::cout << "------- STUDENTS WHO HAS FINISHED -------\n";
    for(const Student *student : studentsWhoHasFinished)
        student->printInformation();
}