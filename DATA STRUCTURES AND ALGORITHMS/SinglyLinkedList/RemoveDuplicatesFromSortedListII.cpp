#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

void removeDupsFromList(Node<int> *&node) {
    if (!node || !node->next)
        return;

    Node<int> *dummy = new Node<int>(0); // Фиктивен възел
    dummy->next = node;
    Node<int> *current = node;

    Node<int> *prev = dummy;

    while (current) {
        bool hasDuplicate = false;

        while (current->next && current->data == current->next->data) {
            hasDuplicate = true;
            Node<int> *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }

        if (hasDuplicate) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }

        else {
            prev = current;
            current = current->next;
        }
    }

    node = dummy->next;
    delete dummy;
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(1);
    node->next->next = new Node<int>(2);
    node->next->next->next = new Node<int>(3);
    node->next->next->next->next = new Node<int>(4);
    node->next->next->next->next->next = new Node<int>(4);
    node->next->next->next->next->next->next = new Node<int>(4);

    removeDupsFromList(node);
    node->printAndFree();
}
