#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *removeDupsFromList(Node<int> *&node) {
    if(!node || !node->next)
        return node;

    Node<int> *dummy = node;
    while(dummy->next != nullptr) {
        if(dummy->data == dummy->next->data)
            dummy->next = dummy->next->next;

        else
            dummy = dummy->next;
    }

    return node;
}

void printList(Node<int> *node) {
    Node<int> *temp = node;
    while(temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }

    std::cout << "nullptr\n";
}

int main() {
    Node<int>* l1 = new Node<int>(1);
    l1->next = new Node<int>(2);
    l1->next->next = new Node<int>(2);

    printList(l1);
    l1 = removeDupsFromList(l1);
    printList(l1);

    while (l1) {
        Node<int>* temp = l1;
        l1 = l1->next;
        delete temp;
    }
}