#include <iostream>
#include <stdexcept>
#include <cassert>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int pp = low;

    for (int i = low; i < high; ++i) {
        if (arr[i] < pivot) {
            ++pp;
            swap(arr[pp], arr[i]);
        }
    }

    swap(arr[pp], arr[high]);
    return pp;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int latestTimeToCatchBus(int* buses, std::size_t n, int* passengers, std::size_t m, int capacity) {
    quickSort(buses, 0, n - 1);
    quickSort(passengers, 0, m - 1);

    int passIndex = 0;
    int latestTime = 0;

    for (std::size_t i = 0; i < n; ++i) {
        int busTime = buses[i];
        int currentCapacity = 0;

        while (passIndex < m && passengers[passIndex] <= busTime && currentCapacity < capacity) {
            currentCapacity++;
            passIndex++;
        }

        if (currentCapacity < capacity)
            latestTime = busTime;

        if (passIndex == 0 || passengers[passIndex - 1] < busTime) {
            for (int t = busTime - 1; t > (passIndex > 0 ? passengers[passIndex - 1] : 0); --t) {
                latestTime = t;
                break;
            }
        }
    }

    return latestTime;
}

int main() {
    std::size_t n = 0, m = 0;
    int capacity = 0;

    std::cout << "Insert number of buses: ";
    std::cin >> n;
    std::cout << "Insert number of passengers: ";
    std::cin >> m;
    std::cout << "Insert capacity of each bus: ";
    std::cin >> capacity;

    if (n <= 0 || m <= 0 || capacity <= 0) {
        std::cerr << "Invalid input values!" << std::endl;
        return 1;
    }

    int* buses = nullptr;
    int* passengers = nullptr;

    try {
        buses = new int[n];
        passengers = new int[m];
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert the departure times of the buses:\n";
    for (std::size_t i = 0; i < n; ++i)
        std::cin >> buses[i];

    std::cout << "Insert the arrival times of the passengers:\n";
    for (std::size_t i = 0; i < m; ++i)
        std::cin >> passengers[i];

    int result = latestTimeToCatchBus(buses, n, passengers, m, capacity);
    std::cout << "Latest time to catch the bus: " << result << std::endl;

    delete[] buses;
    delete[] passengers;

    return 0;
}
