#include <iostream>
#include <stdexcept>
#include <cassert>

struct Seed {
    int plantTime;
    int growTime;
};

void swap(Seed& a, Seed& b) {
    Seed temp = a;
    a = b;
    b = temp;
}

int partition(Seed* arr, int low, int high) {
    int pivot = arr[high].growTime;
    int pp = low;

    for (int i = low; i < high; ++i) {
        if (arr[i].growTime > pivot) {
            ++pp;
            swap(arr[pp], arr[i]);
        }
    }

    swap(arr[pp], arr[high]);
    return pp;
}

void quickSort(Seed* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int earliestFullBloom(Seed* seeds, std::size_t n) {
    quickSort(seeds, 0, n - 1);

    int currentDay = 0, maxBloomDay = 0;

    for (std::size_t i = 0; i < n; ++i) {
        currentDay += seeds[i].plantTime;
        maxBloomDay = std::max(maxBloomDay, currentDay + seeds[i].growTime);
    }

    return maxBloomDay;
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert the number of seeds: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Invalid input\n";
        return 1;
    }

    Seed* seeds = nullptr;
    try {
        seeds = new Seed[n];
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert plantTime and growTime for each seed:\n";
    for (std::size_t i = 0; i < n; ++i)
        std::cin >> seeds[i].plantTime >> seeds[i].growTime;

    int result = earliestFullBloom(seeds, n);
    std::cout << "Earliest possible day for full bloom: " << result << std::endl;

    delete[] seeds;
    return 0;
}
