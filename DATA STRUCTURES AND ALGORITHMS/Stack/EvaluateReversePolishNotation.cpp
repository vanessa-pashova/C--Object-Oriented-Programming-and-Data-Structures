#include <iostream>
#include <stack>
#include <vector>
#include <string>

int getLastAndPopIt(std::stack<int> &stack) {
    int last = stack.top();
    stack.pop();
    return last;
}

int result(std::vector<std::string> &tokens) {
    std::stack<int> stack;

    for (const std::string &token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
            stack.push(std::stoi(token));

        else {
            int last = getLastAndPopIt(stack);
            int preLast = getLastAndPopIt(stack);

            char op = token[0];

            switch (op) {
                case '+':
                    stack.push(preLast + last);
                    break;

                case '-':
                    stack.push(preLast - last);
                    break;

                case '*':
                    stack.push(preLast * last);
                    break;

                case '/':
                    stack.push(preLast / last);
                    break;

                default:
                    throw std::invalid_argument("Invalid operator encountered.");
            }
        }
    }

    return stack.top();
}

int main() {
    std::size_t size = 0;
    std::cout << "Size: ";
    std::cin >> size;

    if (size < 1)
        throw std::invalid_argument("Size cannot be 0.");

    std::vector<std::string> tokens(size);
    for (std::size_t i = 0; i < size; i++)
        std::cin >> tokens[i];

    try {
        std::cout << "Result: " << result(tokens) << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
