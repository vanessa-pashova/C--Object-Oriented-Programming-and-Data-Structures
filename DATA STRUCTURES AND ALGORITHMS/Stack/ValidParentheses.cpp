#include <iostream>
#include <stack>

bool isValid(const std::string string) {
    std::stack<char> stack;

    for(char symbol : string) {
        if(symbol == '(' || symbol == '{' || symbol == '[')
            stack.push(symbol);

        else {
            if(stack.empty())
                return false;

            char top = stack.top();

            if((symbol == ')' && top != '(') ||
                (symbol == '}' && top != '{') ||
                (symbol == ']' && top != '['))
                return false;

            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string string;
    std::cin >> string;

    std::cout << (isValid(string) ? "true" : "false");
}