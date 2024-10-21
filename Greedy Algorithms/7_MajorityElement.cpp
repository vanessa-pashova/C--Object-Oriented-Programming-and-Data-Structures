#include <iostream>
#include <cassert>

int BoyerMooreMajority(int *arr, std::size_t n) {
    int candidate = 0, counter = 0;

    for(std::size_t i = 0; i < n; ++i) {
        if(counter == 0)
            candidate = arr[i];

        if(arr[i] == candidate)
            counter++;

        else
            counter--;
    }

    return candidate;
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert n: ";
    std::cin >> n;

    assert(n > 2);

    try {
        int *nums = new int[n];

        std::cout << "Insert values for the array:\n";
        for(std::size_t i = 0; i < n; ++i)
            std::cin >> nums[i];

        std::cout << BoyerMooreMajority(nums, n) << '\n';

        delete [] nums;
    }

    catch(const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }

    return 0;
}