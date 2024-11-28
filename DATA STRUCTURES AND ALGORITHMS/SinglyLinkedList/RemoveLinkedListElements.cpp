#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

void removeElementsWithValue(Node<int> *&node, int value) {
    while(node && node->data == value) {
        Node<int> *temp = node;
        node = node->next;
        delete temp;
    }

    Node<int> *current = node;
    while(current && current->next) {
        if(current->next->data == value) {
            Node<int> *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }

        else
            current = current->next;
    }
}

int main() {
    Node<int> *node = new Node<int>(4);
    node->next = new Node<int>(1);
    node->next->next = new Node<int>(8);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    node->printAndFree();

    Node<int> *node1 = new Node<int>(4);
    node1->next = new Node<int>(1);
    node1->next->next = new Node<int>(8);
    node1->next->next->next = new Node<int>(4);
    node1->next->next->next->next = new Node<int>(5);

    removeElementsWithValue(node1, 4);
    node1->printAndFree();
}