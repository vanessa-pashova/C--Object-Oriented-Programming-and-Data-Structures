#include <iostream>
#include <cassert>

void merge(int *arr, int low, int mid, int high) {
    std::size_t n1 = mid - low + 1,
                n2 = high - mid;

    assert(n1 > 0 && n2 > 0);

    int *left = nullptr,
        *right = nullptr;
    try {
        left = new int[n1];
        right = new int[n2];
    } catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        delete [] left;
        delete [] right;
        throw;
    }

    for(std::size_t i = 0; i < n1; ++i)
        left[i] = arr[low + i];

    for(std::size_t i = 0; i < n2; ++i)
        right[i] = arr[mid + 1 + i];

    std::size_t i = 0, j = 0, k = low;

    while(i < n1 && j < n2) {
        if(left[i] < right[j])
            arr[k++] = left[i++];

        else
            arr[k++] = right[j++];
    }

    while(i < n1)
        arr[k++] = left[i++];

    while(j < n2)
        arr[k++] = right[j++];

    delete [] left;
    delete [] right;
}

void mergeSort(int *arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int minimizedPairSum(int *&arr, std::size_t &size) {
    int maxSum = 0;

    for(std::size_t i = 0; i < size / 2; ++i) {
        int currentSum = arr[i] + arr[size - 1 - i];
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    std::size_t size = 0;
    std::cout << "Insert a size for the array: ";
    std::cin >> size;

    assert(size % 2 == 0);

    int *nums = nullptr;
    try {
        nums = new int[size];
    } catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert values for the array:\n";
    for(std::size_t i = 0; i < size; ++i)
        std::cin >> nums[i];

    mergeSort(nums, 0, size - 1);

    std::cout << "Minimized sum of the pairs is: " << minimizedPairSum(nums, size) << '\n';

    delete [] nums;
    return 0;
}