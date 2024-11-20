#include <iostream>
#include <stack>
#include "../Structs_Ready/LinkedListNode.h"

template <typename T>
bool isPalindrom(Node<T>* node) {
    std::stack<T> stack;
    Node<T>* current = node;

    while (current != nullptr) {
        stack.push(current->data);
        current = current->next;
    }

    current = node;

    while (current != nullptr) {
        if (current->data != stack.top())
            return false;

        stack.pop();
        current = current->next;
    }

    return true;
}

int main() {
    Node<int>* node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(2);
    node->next->next->next = new Node<int>(1);

    std::cout << (isPalindrom(node) ? "palindrom" : "not palindrom") << '\n';

    while (node != nullptr) {
        Node<int>* temp = node;
        node = node->next;
        delete temp;
    }

    return 0;
}
