#include <iostream>
#include <stack>

std::stack<char> stringOperation(std::string &string) {
    std::stack<char> stack;

    for(char symbol : string) {
        if(symbol == '#' && !stack.empty())
            stack.pop();

        else
            stack.push(symbol);
    }

    return stack;
}

bool compare(std::stack<char> st1, std::stack<char> st2) {
    if(st1.size() != st2.size())
        return false;

    else {
        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }
    }

    return true;
}

int main() {
    std::string input1, input2;
    std::cin >> input1;
    std::cin >> input2;

    if(input1.empty() || input2.empty())
        throw std::invalid_argument("Input cannot be empty");

    else
        std::cout << (compare(stringOperation(input1), stringOperation(input2)) ? "true" : "false");
}