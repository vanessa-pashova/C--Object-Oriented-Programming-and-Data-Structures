#include <iostream>
#include <vector>
#include <stack>

std::stack<int> finalPrices(const std::vector<int> &vec) {
    if(vec.size() == 0 || vec.empty())
        throw std::invalid_argument("Vector cannot be empty");

    std::stack<int> stack;

    for(int i = 0; i < vec.size() - 1; i++) {
        int current = vec[i];
        bool discount = false;

        for(int j = i + 1; j < vec.size(); j++) {
            int next = vec[j];

            if((current % next == 0) && (current >= next)) {
                stack.push((current - next));
                discount = true;
                break;
            }
        }

        if(!discount)
            stack.push(current);
    }

    stack.push(vec[vec.size() - 1]);

    return stack;
}

void printStack(std::stack<int> stack) {
    std::stack<int> temp;

    while(!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }

    while(!temp.empty()) {
        stack.push(temp.top());
        std::cout << temp.top() << ' ';
        temp.pop();
    }

    std::cout << '\n';
}

int main() {
    std::vector<int> prices;
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(6);
    prices.push_back(2);
    prices.push_back(3);

    std::vector<int> prices1;
    prices1.push_back(1);
    prices1.push_back(2);
    prices1.push_back(3);
    prices1.push_back(4);
    prices1.push_back(5);

    try {
        printStack(finalPrices(prices));
        printStack(finalPrices(prices1));
    } catch (std::runtime_error e) {
        std::cerr << "Error occupied.";
        e.what();
    }
}