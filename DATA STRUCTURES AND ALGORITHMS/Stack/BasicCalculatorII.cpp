#include <iostream>
#include <string>
#include <stack>

int calculate(const std::string &expr) {
    std::stack<int> stack;
    int currentNumber = 0;
    char currentOperator = '+';

    for (std::size_t i = 0; i <= expr.length(); ++i) {
        char ch = (i < expr.length()) ? expr[i] : '\0';

        if ('0' <= ch && ch <= '9')
            currentNumber = currentNumber * 10 + (ch - '0');

        if ((ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0') && ch != ' ') {
            if (currentOperator == '+')
                stack.push(currentNumber);

            else if (currentOperator == '-')
                stack.push(-currentNumber);

            else if (currentOperator == '*') {
                int top = stack.top();
                stack.pop();
                stack.push(top * currentNumber);
            }

            else if (currentOperator == '/') {
                int top = stack.top();
                stack.pop();
                stack.push(top / currentNumber);
            }

            currentOperator = ch;
            currentNumber = 0;
        }
    }

    int result = 0;
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }

    return result;
}

int main() {
    std::string expression;
    std::cout << "Enter expression: ";
    std::getline(std::cin, expression);

    try {
        std::cout << "Result: " << calculate(expression) << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
