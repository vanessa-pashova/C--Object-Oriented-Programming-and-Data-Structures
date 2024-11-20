#include <iostream>
#include <stack>

std::stack<char> removeOutermostParentheses(const std::string &string) {
    std::stack<char> stack;
    std::stack<char> result;

    int depth = 0;

    for(char current : string) {
        if(current == '(') {
            if(depth > 0)
                result.push(current);

            stack.push(current);
            depth++;
        }

        else if(current == ')') {
            depth--;

            if(depth > 0)
                result.push(current);

            stack.pop();
        }
    }

    return result;
}

void printStack(std::stack<char> stack) {
    std::stack<char> temp;

    while(!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }

    while(!temp.empty()) {
        std::cout << temp.top();
        temp.pop();
    }

    std::cout << std::endl;
}

int main() {
    std::string input;
    std::cin >> input;

    try {
        printStack(removeOutermostParentheses(input));
    } catch (std::invalid_argument e) {
        std::runtime_error("Error occupied.");
        return 1;
    }
}