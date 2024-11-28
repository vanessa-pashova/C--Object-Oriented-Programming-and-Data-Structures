#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *middleOfList(Node<int> *node) {
    Node<int> *slow = node, *fast = node;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<int> *result = slow;
    return result;
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    Node<int> *middlePart = middleOfList(node);
    middlePart->printAndFree();
}