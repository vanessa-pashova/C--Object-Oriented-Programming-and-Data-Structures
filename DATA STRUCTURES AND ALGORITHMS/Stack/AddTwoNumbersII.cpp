#include <iostream>
#include <stack>
#include "../Structs_Ready/LinkedListNode.h"

std::stack<int> calculation(std::stack<Node<int>*> &st1, std::stack<Node<int>*> &st2) {
    std::stack<int> result;
    bool plusOne = false;

    while (!st1.empty() || !st2.empty() || plusOne) {
        int value = plusOne ? 1 : 0;

        if (!st1.empty()) {
            value += st1.top()->data;
            st1.pop();
        }

        if (!st2.empty()) {
            value += st2.top()->data;
            st2.pop();
        }

        result.push(value % 10);
        plusOne = value >= 10;
    }

    return result;
}

Node<int>* createNodeAfterCalc(std::stack<int> result) {
    Node<int>* node = nullptr;

    while (!result.empty()) {
        Node<int>* temp = new Node<int>(result.top());
        temp->next = node;
        node = temp;
        result.pop();
    }

    return node;
}

Node<int>* addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    std::stack<Node<int>*> st1, st2;

    while (l1) {
        st1.push(l1);
        l1 = l1->next;
    }

    while (l2) {
        st2.push(l2);
        l2 = l2->next;
    }

    std::stack<int> calc = calculation(st1, st2);
    return createNodeAfterCalc(calc);
}

void printList(Node<int>* node) {
    while (node) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << '\n';
}

int main() {
    Node<int>* node1 = new Node<int>(7);
    node1->next = new Node<int>(2);
    node1->next->next = new Node<int>(4);
    node1->next->next->next = new Node<int>(3);

    Node<int>* node2 = new Node<int>(5);
    node2->next = new Node<int>(6);
    node2->next->next = new Node<int>(4);

    printList(addTwoNumbers(node1, node2));
}
