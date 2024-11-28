#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *reverseList(Node<int> *node) {
    Node<int> *prev = nullptr, *current = node, *next = nullptr;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    node->printAndFree();

    Node<int> *node2 = new Node<int>(1);
    node2->next = new Node<int>(2);
    node2->next->next = new Node<int>(3);
    node2->next->next->next = new Node<int>(4);
    node2->next->next->next->next = new Node<int>(5);

    node2 = reverseList(node2);
    node2->printAndFree();
}