#include <iostream>
#include <cassert>

int *sortSquates(int *arr, std::size_t n) {
    int *result = new int[n];

    std::size_t left = 0, right = n - 1, index = n - 1;

    while(left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if(leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        }

        else {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
}

int main() {
    std::size_t n = 0;
    std::cout << "Number of elements: ";
    std::cin >> n;

    try {
        assert(n > 2);
        int *nums = new int[n];

        std::cout << "Insert the values of the array: ";
        for(std::size_t i = 0; i < n; ++i)
            std::cin >> nums[i];

        int* result = sortSquates(nums, n);
        for(std::size_t i = 0; i < n; ++i)
            std::cout << result[i] << " ";

        delete [] nums;
        delete [] result;
    }

    catch(std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }
}