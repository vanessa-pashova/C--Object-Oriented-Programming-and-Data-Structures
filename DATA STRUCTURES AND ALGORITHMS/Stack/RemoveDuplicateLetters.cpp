#include <iostream>
#include <string>
#include <stack>

std::string removeDups(std::string &str) {
    std::stack<char> stack;
    bool inStack[128] = {false};
    int count[128] = {0};

    for (char ch : str)
        count[ch]++;

    for (char ch : str) {
        count[ch]--;

        if (inStack[ch])
            continue;

        while (!stack.empty() && stack.top() > ch && count[stack.top()] > 0) {
            inStack[stack.top()] = false;
            stack.pop();
        }

        stack.push(ch);
        inStack[ch] = true;
    }

    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
}

int main() {
    std::string string;
    std::cout << "Insert a string: ";
    std::cin >> string;

    if (string.empty() || string.length() == 0)
        throw std::invalid_argument("String must not be empty.");

    std::cout << "Result: " << removeDups(string) << '\n';
}
