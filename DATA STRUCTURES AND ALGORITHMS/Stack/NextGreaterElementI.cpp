#include <iostream>
#include <stack>
#include <vector>

std::stack<int> nextGreaterElement(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    if(nums1.empty() || nums2.empty())
        throw std::invalid_argument("Vectors cannot be empty.");

    std::stack<int> stack;

    for(int current : nums1) {
        bool found = false, pushed = false;

        for(int i = 0; i < nums2.size(); i++) {
            if(current == nums2[i])
                found = true;

            if(found && (i + 1 < nums2.size()) && (current < nums2[i + 1])) {
                stack.push(nums2[i + 1]);
                pushed = true;
                break;
            }
        }

        if(!pushed)
            stack.push(-1);
    }

    return stack;
}

void print(const std::stack<int> &stack) {
    std::stack<int> temp = stack;

    while(!temp.empty()) {
        std::cout << temp.top() << ' ';
        temp.pop();
    }
}

int main() {
    std::vector<int> arr1;
    std::vector<int> arr2;

    arr1.push_back(4);
    arr1.push_back(1);
    arr1.push_back(2);

    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(4);
    arr2.push_back(2);

    std::stack<int> result = nextGreaterElement(arr1, arr2);
    print(result);
}
