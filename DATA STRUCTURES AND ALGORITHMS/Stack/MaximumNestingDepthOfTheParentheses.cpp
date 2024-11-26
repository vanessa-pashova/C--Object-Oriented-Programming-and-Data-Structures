#include <iostream>
#include <string>
#include <stack>

std::size_t getDepthOfString(std::string str) {
    std::stack<char> stack;
    std::size_t depth = 0, currentDepth = 0;

    for(char ch : str) {
        if(currentDepth > depth)
            depth = currentDepth;

        if(ch == '(') {
            stack.push(ch);
            currentDepth++;
        }

        if(ch == ')') {
            stack.pop();
            currentDepth--;
        }

        else
            continue;
    }

    return depth;
}

int main() {
    std::string str;
    std::cin >> str;

    if(str.empty() || str.length() == 0)
        throw std::invalid_argument("String must not be empty.");

    std::cout << "Depth of the string: " << getDepthOfString(str) << '\n';
}