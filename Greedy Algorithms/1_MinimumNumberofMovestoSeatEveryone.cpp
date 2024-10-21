#include <iostream>
#include <cmath>

template <typename T>
void selectionSort(T* arr, int n) {
    for(int i = 0; i < n - 1; ++i) {
        int minIdx = i;

        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        std::swap(arr[i], arr[minIdx]);
    }
}

template <typename T>
int minMovesToSeat(T* seats, T* students, int n) {
    selectionSort(seats, n);
    selectionSort(students, n);

    int total = 0;
    for(int i = 0; i < n; ++i)
        total += abs(students[i] - seats[i]);

    return total;
}

int main() {
    int n = 0;
    std::cout << "Insert the number of the students and te seats: ";
    std::cin >> n;

    try {
        int* seats = new int[n];
        int* students = new int[n];

        std::cout << "Insert the positions of the seats:\n";
        for(int i = 0; i < n; ++i)
            std::cin >> seats[i];

        std::cout << std::endl;
        std::cout << "Insert the positions of the students:\n";
        for(int i = 0; i < n; ++i)
            std::cin >> students[i];

        std::cout << "Minimal total number of moves to be done is: " << minMovesToSeat(students, seats, n) << '\n';

        delete [] seats;
        delete [] students;
    }

    catch(const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }

    catch(...) {
        std::cout << "Some kind of error\n";
        return 1;
    }

    return 0;
}