#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> s1, s2;

public:
    MyQueue() = default;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int top = s2.top();
        s2.pop();

        return top;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    std::cout << "First element before pop(): " << queue.peek() << '\n';

    queue.pop();
    std::cout << "First element after pop(): " << queue.peek() << '\n';

    std::cout << (queue.empty() ? "empty" : "not empty") << '\n';

    return 0;
}
