#include <iostream>
#include <string>
#include <stack>

int main() {
    unsigned int logsCount = 0, minOperationsCount = 0;
    std::cout << "Insert size of the arr: ";
    std::cin >> logsCount;

    std::stack<std::string> stack;
    while(logsCount > 1) {
        std::string log;
        std::cin >> log;

        if(log == "./")
            continue;

        else if(log == "../") {
            if(!stack.empty()) {
                stack.pop();
                minOperationsCount--;
            }

            else
                minOperationsCount = 0;
        }

        else if(log.back() == '/') {
            stack.push(log);
            minOperationsCount++;
        }

        else
            throw std::invalid_argument("Invalid argument given");

        logsCount--;
    }

    std::cout << "Minimal operations to go back to the root: " << minOperationsCount << '\n';
}