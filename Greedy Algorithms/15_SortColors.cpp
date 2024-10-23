#include <iostream>
#include <cassert>

void dijkstraSort(int *nums, std::size_t size) {
    std::size_t low = 0, mid = 0, high = size - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if(nums[mid] == 1)
            mid++;

        else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void print(int *&arr, std::size_t &n) {
    for(std::size_t i = 0; i < n; ++i)
        std::cout << arr[i] << " ";

    std::cout << '\n';
}

int main() {
    std::size_t size = 0;
    std::cout << "Insert how many elements you're going to insert: ";
    std::cin >> size;

    assert(size > 0);

    int *colours = new (std::nothrow) int[size];
    if(!colours) {
        std::cerr << "Memory allocation problem\n";
        delete [] colours;
        return 1;
    }

    for(std::size_t i = 0; i < size; ++i)
        std::cin >> colours[i];

    std::cout << "Before sorting: ";
    print(colours, size);

    dijkstraSort(colours, size);

    std::cout << "After sorting: ";
    print(colours, size);
}