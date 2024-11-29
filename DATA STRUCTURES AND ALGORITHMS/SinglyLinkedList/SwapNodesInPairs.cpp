#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

void swapNodes(Node<int> *&node) {
    if (!node || !node->next)
        return;

    Node<int> *current = node;
    Node<int> *prev = nullptr;

    while (current && current->next) {
        Node<int> *nextPair = current->next->next;
        Node<int> *second = current->next;

        second->next = current;
        current->next = nextPair;

        if (!prev)
            node = second;

        else
            prev->next = second;

        prev = current;
        current = nextPair;
    }
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);
    node->next->next->next->next->next = new Node<int>(6);

    swapNodes(node);
    node->printAndFree();
}
