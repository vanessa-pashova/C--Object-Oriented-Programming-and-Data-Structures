#include <iostream>

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int pp = low;

    for (std::size_t i = low; i < high; ++i) {
        if (arr[i] > pivot) {
            std::swap(arr[i], arr[pp]);
            pp++;
        }
    }

    std::swap(arr[pp], arr[high]);
    return pp;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int total(int *&piles, std::size_t &arraySize) {
    int total = 0;
    for (std::size_t i = 1; i < arraySize; i += 3)
        total += piles[i];

    return total;
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert a value for n: ";
    std::cin >> n;

    std::size_t arraySize = n * 3;

    int *piles = new(std::nothrow) int[arraySize];
    if (!piles) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert values for the array:\n";
    for (std::size_t i = 0; i < arraySize; ++i)
        std::cin >> piles[i];

    quickSort(piles, 0, arraySize - 1);

    std::cout << "Maximum I can get is: " << total(piles, arraySize) << '\n';

    delete[] piles;
    return 0;
}
