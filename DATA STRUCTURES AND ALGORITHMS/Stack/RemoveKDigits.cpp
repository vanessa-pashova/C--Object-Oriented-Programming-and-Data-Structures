#include <iostream>
#include <string>
#include <stack>

std::string removeKdigits(std::string &num, int k) {
    std::stack<char> stack;

    for(char digit : num) {
        while(!stack.empty() && (0 < k) && (stack.top() > digit)) {
            stack.pop();
            k--;
        }

        if(!stack.empty() || digit != '0')
            stack.push(digit);
    }

    while(k > 0 && !stack.empty()) {
        stack.pop();
        k--;
    }

    std::string result;
    while(!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result.empty() ? "0" : result;
}

int main() {
    std::string num;
    std::cout << "Insert a num: ";
    std::cin >> num;

    if (num.empty() || num.length() == 0)
        throw std::invalid_argument("Num must not be empty.");

    unsigned int k;
    std::cout << "Insert a value for k: ";
    std::cin >> k;

    if(num.size() < k)
        throw std::logic_error("k must not be greater than the number of the digits of Num.");

    std::cout << "Result: " << removeKdigits(num, k) << '\n';
}