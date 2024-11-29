#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

void removeNthElement(Node<int> *&node, int k) {
    if(!node)
        return;

    if(k == 0) {
        Node<int> *temp = node;
        node = node->next;
        delete temp;
        return;
    }

    int counter = 0;
    Node<int> *current = node;

    while(current && current->next) {
        if(counter == k - 1) {
            Node<int> *temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }

        counter++;
        current = current->next;
    }
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    removeNthElement(node, 2);
    node->printAndFree();
}