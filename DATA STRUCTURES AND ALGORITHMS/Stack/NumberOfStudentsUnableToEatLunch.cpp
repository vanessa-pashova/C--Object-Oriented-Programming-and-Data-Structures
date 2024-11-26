#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::size_t count = 0, choice = 0;
    std::cin >> count;

    std::queue<int> students;
    for (std::size_t i = 0; i < count; i++) {
        std::cin >> choice;
        students.push(choice);
    }

    std::stack<int> sandwiches;
    for (std::size_t i = 0; i < count; i++) {
        std::cin >> choice;
        sandwiches.push(choice);
    }

    int unableToEat = 0;
    while (!sandwiches.empty() && unableToEat < students.size()) {
        if (sandwiches.top() == students.front()) {
            sandwiches.pop();
            students.pop();
            unableToEat = 0;
        }

        else {
            int temp = students.front();
            students.pop();
            students.push(temp);
            unableToEat++;
        }
    }

    std::cout << students.size() << '\n';
}
