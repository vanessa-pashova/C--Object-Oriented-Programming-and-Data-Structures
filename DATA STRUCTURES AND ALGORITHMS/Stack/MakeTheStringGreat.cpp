#include <iostream>
#include <stack>

std::stack<char> twoAdjacentCharacters(const std::string &string) {
    std::stack<char> stack;

    for(char ch : string) {
        if(stack.empty()) {
            stack.push(ch);
            continue; //without it in else the same ch will be pushed again
        }

        if((('a' <= ch && ch <= 'z') && ('A' <= stack.top() && stack.top() <= 'Z')) ||
            (('A' <= ch && ch <= 'Z') && ('a' <= stack.top() && stack.top() <= 'z')))
            stack.pop();

        else
            stack.push(ch);
    }

    return stack;
}

std::stack<char> reverseStack(std::stack<char> stack) {
    std::stack<char> reversed;

    while(!stack.empty()) {
        reversed.push(stack.top());
        stack.pop();
    }

    return reversed;
}

std::string convertToString(std::stack<char> stack) {
    std::string result;

    while(!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}

int main() {
    std::string input;
    std::cin >> input;

    if(input.empty() || input.length() == 0)
        throw std::invalid_argument("Input cannot be empty.");

    try {
        std::cout << convertToString(reverseStack(twoAdjacentCharacters(input)));
    } catch (std::runtime_error) {
        std::cerr << "Error occupied.";
        return 1;
    }
}