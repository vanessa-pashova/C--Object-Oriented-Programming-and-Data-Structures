#include <iostream>
#include <stack>

std::stack<char> removeAllAdjacentDuplicatesInString(const std::string &string) {
    std::stack<char> stack;

    for(char ch : string ) {
        if(stack.empty()) {
            stack.push(ch);
            continue;
        }

        if(ch == stack.top())
            stack.pop();

        else
            stack.push(ch);
    }

    return stack;
}

void printStack(const std::stack<char> &stack) {
    std::stack<char> temp = stack;

    std::stack<char> reversed;
    while(!temp.empty()) {
        reversed.push(temp.top());
        temp.pop();
    }

    while(!reversed.empty()) {
        std::cout << reversed.top();
        reversed.pop();
    }

    std::cout << '\n';
}

int main() {
    std::string input;

    try {
        std::cin >> input;
        printStack(removeAllAdjacentDuplicatesInString(input));
    } catch (std::invalid_argument e) {
        std::cerr << "Input cannot be empty.\n";
        return 1;
    }
}