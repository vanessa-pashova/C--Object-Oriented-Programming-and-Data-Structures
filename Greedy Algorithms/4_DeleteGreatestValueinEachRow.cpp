#include <iostream>

void selectionSort(int* arr, std::size_t n) {
    for (std::size_t i = 0; i < n - 1; ++i) {
        std::size_t minIdx = i;

        for (std::size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        std::swap(arr[i], arr[minIdx]);
    }
}

int total(int** arr, std::size_t m, std::size_t n) {
    int total = 0;

    for (std::size_t i = 0; i < m; ++i) {
        selectionSort(arr[i], n);
        total += arr[i][n - 1];
        n--;
    }

    return total;
}

int main() {
    std::size_t m, n = 0;
    std::cout << "Insert values for m and n: ";
    std::cin >> m >> n;

    try {
        int** grid = new int*[m];
        for (std::size_t i = 0; i < m; ++i)
            grid[i] = new int[n];

        for (std::size_t i = 0; i < m; ++i) {
            std::cout << "Insert the values of the " << i + 1 << "-th row: ";

            for (std::size_t j = 0; j < n; ++j)
                std::cin >> grid[i][j];
        }

        std::cout << "Total: " << total(grid, m, n) << '\n';

        for (std::size_t i = 0; i < m; ++i)
            delete[] grid[i];

        delete[] grid;
    }

    catch (const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }

    return 0;
}
