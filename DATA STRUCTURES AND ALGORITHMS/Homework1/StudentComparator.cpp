#include "Student.h"

struct CompareStudentsCourses {
    bool operator()(const Student* student1, const Student* student2) const {
        // Проверка за курса на студентите
        if (student1->getCourse() == 2 && student2->getCourse() != 2)
            return false; // student1 има предимство

        if (student2->getCourse() == 2 && student1->getCourse() != 2)
            return true; // student2 има предимство

        // Ако курсът е еднакъв, проверяваме времето на пристигане
        return student1->getArrivalTime() > student2->getArrivalTime();
        // По-ранното време има предимство (по-малко време).
    }
};
