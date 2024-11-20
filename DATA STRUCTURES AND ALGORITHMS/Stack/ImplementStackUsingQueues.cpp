#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2;

public:
    MyStack() = default;

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        std::swap(q1, q2);
    }

    int pop() {
        int top = q1.front();

        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();
    stack->push(1);
    stack->push(2);
    stack->push(3);

    std::cout << "Stack top: " << stack->top() << '\n';

    stack->pop();
    std::cout << "Stack top: " << stack->top() << '\n';

    std::cout << ((stack->empty()) ? "true" : "false");
}