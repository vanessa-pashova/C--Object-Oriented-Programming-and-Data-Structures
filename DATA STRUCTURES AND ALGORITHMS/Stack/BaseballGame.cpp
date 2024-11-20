#include <iostream>
#include <stack>

int calculation(const std::string &operations) {
    std::stack<int> recorder;

    for(char operation : operations) {
        if('0' <= operation && operation <= '9') {
            int score = operation - '0';
            recorder.push(score);
        }

        else if(operation == '+') {
            if(recorder.size() >= 2) {
                int temp = recorder.top();
                recorder.pop();
                int opAddition = temp + recorder.top();

                recorder.push(temp);
                recorder.push(opAddition);
            }

            else
                throw std::runtime_error("Not enough elements in stack for '+' operation.");
        }

        else if(operation == 'D')
            recorder.push(recorder.top() * 2);

        else if(operation == 'C')
            recorder.pop();

        else
            throw std::invalid_argument("Invalid argument given in the string.");
    }

    int sum = 0;

    while(!recorder.empty()) {
        sum += recorder.top();
        recorder.pop();
    }

    return sum;
}

int main() {
    std::string operations;
    std::cin >> operations;

    std::cout << "Total score: " << calculation(operations);
}