#include <iostream>

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int pp = low;

    for(std::size_t i = low; i < high; ++i) {
        if(arr[i] > pivot) {
            std::swap(arr[i], arr[pp]);
            pp++;
        }
    }

    std::swap(arr[pp], arr[high]);
    return pp;
}

void quickSort(int* arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int totalSum(int *arr, std::size_t n) {
    int total = 0;

    for(std::size_t i = 0; i < n; ++i)
        total += arr[i];

    return total;
}

int subseqSize(int *arr, std::size_t n) {
    int total = totalSum(arr, n);
    int max = 0;
    std::size_t size = 0;

    for(std::size_t i = 0; i < n; ++i) {
        max += arr[i];
        size++;

        if(max > total - max)
            break;
    }

    return size;
}

int *subseq(int *arr, std::size_t n) {
    std::size_t size = subseqSize(arr, n);

    try {
        int *result = new int[size];
        for(std::size_t i = 0; i < size; ++i)
            result[i] = arr[i];

        return result;
    }

    catch(const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return nullptr;
    }
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert n: ";
    std::cin >> n;

    try {
        int* nums = new int[n];

        std::cout << "Insert the values of the array:\n";
        for(std::size_t i = 0; i < n; ++i)
            std::cin >> nums[i];

        quickSort(nums, 0, n - 1);
        int *result = subseq(nums, n);
        int resultSize = subseqSize(nums, n);

        std::cout << "[ ";
        for(std::size_t i = 0; i < resultSize - 1; ++i)
            std::cout << result[i] << ',' << ' ';

        std::cout << result[resultSize - 1] << " ]";

        delete [] nums;
        delete [] result;
    }

    catch(const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }
}