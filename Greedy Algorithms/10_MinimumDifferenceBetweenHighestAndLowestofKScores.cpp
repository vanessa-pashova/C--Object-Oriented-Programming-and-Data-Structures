#include <iostream>
#include <cassert>

void merge(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1,
        n2 = high - mid;

    assert(n1 > 0 && n2 > 0);

    int *left = nullptr,
        *right = nullptr;

    try {
        left = new int[n1];
        right = new int[n2];
    }

    catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        delete [] left;
        delete [] right;
        throw;
    }

    for(std::size_t i = 0; i < n1; ++i)
        left[i] = arr[low + i];

    for(std::size_t i = 0; i < n2; ++i)
        right[i] = arr[mid + i + 1];

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
    assert(low >= 0 && high >= 0);

    if(low < high) {
        int mid = low + (high - low) / 2;
        assert(low <= mid && mid < high);

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int minDiff(int *arr, std::size_t size, int k) {
    if(k == 1)
        return 0;

    mergeSort(arr, 0, size - 1);

    int minDiff = arr[k - 1] - arr[0];

    for(std::size_t i = 1; i <= size - k; ++i) {
        int diff = arr[k + i - 1] - arr[i];
        minDiff = std::min(minDiff, diff);
    }

    return minDiff;
}

int main() {
    std::size_t size = 0, k = 0;
    std::cout << "Insert the number of the students: ";
    std::cin >> size;
    std::cout << "Insert a value for k: ";
    std::cin >> k;

    assert(size > 0 && k > 0);

    int *nums = new(std::nothrow) int[size];
    if(!nums) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert the values of the array:\n";
    for(std::size_t i = 0; i < size; ++i)
        std::cin >> nums[i];

    std::cout << "Minimal difference: " << minDiff(nums, size, k) << '\n';

    delete [] nums;
}