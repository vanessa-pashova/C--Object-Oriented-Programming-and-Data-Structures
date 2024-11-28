#include <iostream>
#include <stack>

bool ifPattern(int *arr, std::size_t size) {
    if (size < 3)
        return false;

    std::stack<int> stack;
    int last = INT_MIN;

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < last)
            return true;

        while (!stack.empty() && arr[i] > stack.top()) {
            last = stack.top();
            stack.pop();
        }

        stack.push(arr[i]);
    }

    return false;
}

int main() {
    std::size_t size = 0;
    std::cout << "Insert a size for the array: ";
    std::cin >> size;

    if(size == 0)
        throw std::invalid_argument("Array must not be empty.");

    int *arr = new int[size];
    for(std::size_t i = 0; i < size; i++)
        std::cin >> arr[i];

    std::cout << (ifPattern(arr, size) ? "True" : "False") << '\n';

    delete [] arr;
}