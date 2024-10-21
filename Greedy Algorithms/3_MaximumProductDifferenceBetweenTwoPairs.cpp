#include <iostream>

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int pp = low;

    for(int i = low; i < high; ++i) {
        if(arr[i] <= pivot) {
            std::swap(arr[i], arr[pp]);
            pp++;
        }
    }

    std::swap(arr[pp], arr[high]);
    return pp;
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int maxDiff(int *arr, std::size_t n) {
    return (arr[n - 1] * arr[n - 2]) - (arr[0] * arr[1]);
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert how many pairs you will insert: ";
    std::cin >> n;

    try {
        int* nums = new int[n];

        std::cout << "Please, insert the coordinates:\n";
        for(std::size_t i = 0; i < n; ++i)
            std::cin >> nums[i];

        quickSort(nums, 0, n - 1);

        std::cout << "Max difference: " << maxDiff(nums, n);

        delete [] nums;
    }

    catch(const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }

    return 0;
}