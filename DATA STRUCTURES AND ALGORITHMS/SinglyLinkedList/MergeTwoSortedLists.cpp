#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int>* mergeLists(Node<int>* l1, Node<int>* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node<int> dummy(0);
    Node<int>* tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }

        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(Node<int>* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    Node<int>* l1 = new Node<int>(1);
    l1->next = new Node<int>(2);
    l1->next->next = new Node<int>(4);

    Node<int>* l2 = new Node<int>(1);
    l2->next = new Node<int>(3);
    l2->next->next = new Node<int>(4);

    std::cout << "List 1: ";
    printList(l1);

    std::cout << "List 2: ";
    printList(l2);

    Node<int>* mergedList = mergeLists(l1, l2);
    std::cout << "Merged List: ";
    printList(mergedList);

    while (mergedList) {
        Node<int>* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }
}