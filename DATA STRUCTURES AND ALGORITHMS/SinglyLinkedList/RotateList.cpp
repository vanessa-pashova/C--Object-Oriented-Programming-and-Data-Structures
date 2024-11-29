#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *getLastNodeAndPopIt(Node<int> *&node) {
    if (!node || !node->next) {
        Node<int> *result = node;
        node = nullptr;
        return result;
    }

    Node<int> *current = node;
    while (current->next && current->next->next)
        current = current->next;

    Node<int> *result = current->next;
    current->next = nullptr;
    return result;
}

void rotation(Node<int> *&node, unsigned int k) {
    if (!node || !node->next) return;

    for (std::size_t i = 0; i < k; i++) {
        Node<int> *lastNode = getLastNodeAndPopIt(node);

        if (lastNode) {
            lastNode->next = node;
            node = lastNode;
        }
    }
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);
    node->next->next->next->next->next = new Node<int>(6);

    unsigned int k = 2;
    rotation(node, k);
    node->printAndFree();
}
