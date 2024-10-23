#include <iostream>
#include <cassert>

void insertValue(std::size_t &element, const std::string &type) {
    std::cout << "Insert integer value for the number of the " << type << ": ";
    std::cin >> element;
}

void swapRows(int **arr, std::size_t row1, std::size_t row2) {
    int *temp = arr[row1];
    arr[row1] = arr[row2];
    arr[row2] = temp;
}

int partition(int **arr, int low, int high, std::size_t k) {
    int pivot = arr[high][k];
    int pp = low;

    for (std::size_t i = low; i < high; ++i) {
        if (arr[i][k] > pivot) {
            swapRows(arr, pp, i);
            pp++;
        }
    }

    swapRows(arr, pp, high);
    return pp;
}

void quickSort(int **arr, int low, int high, std::size_t k) {
    if (low < high) {
        int pi = partition(arr, low, high, k);

        quickSort(arr, low, pi - 1, k);
        quickSort(arr, pi + 1, high, k);
    }
}

void print(int **&schoolClass, std::size_t &students, std::size_t &exams) {
    for (std::size_t i = 0; i < students; ++i) {
        for (std::size_t j = 0; j < exams; ++j)
            std::cout << schoolClass[i][j] << ' ';

        std::cout << '\n';
    }
}

int main() {
    std::size_t students = 0, exams = 0, k = 0;
    insertValue(students, "students");
    insertValue(exams, "exams");

    insertValue(k, "k");
    assert(k < exams);

    int **schoolClass = new (std::nothrow) int*[students];
    if (!schoolClass) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    for (std::size_t i = 0; i < students; ++i) {
        schoolClass[i] = new (std::nothrow) int[exams];
        if (!schoolClass[i]) {
            std::cerr << "Memory allocation problem for row " << i << '\n';
            return 1;
        }
    }

    std::cout << "Insert the scores for each student:\n";
    for (std::size_t i = 0; i < students; ++i) {
        std::cout << "Student " << i + 1 << " scores: ";

        for (std::size_t j = 0; j < exams; ++j)
            std::cin >> schoolClass[i][j];
    }

    std::cout << "Matrix before:\n";
    print(schoolClass, students, exams);

    quickSort(schoolClass, 0, students - 1, k);

    std::cout << '\n';

    std::cout << "Matrix after:\n";
    print(schoolClass, students, exams);

    for (std::size_t i = 0; i < students; ++i)
        delete[] schoolClass[i];

    delete[] schoolClass;

    return 0;
}
