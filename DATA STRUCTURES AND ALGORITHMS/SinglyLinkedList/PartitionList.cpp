#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *partitionList(Node<int> *head, int x) {
    if(!head || !head->next)
        return head;

    Node<int> firstHalf(0), secondHalf(0);
    Node<int> *less = &firstHalf, *greater = &secondHalf, *current = head;
    while(current) {
        if(current->data < x) {
            less->next = current;
            less = less->next;
        }

        else {
            greater->next = current;
            greater = greater->next;
        }

        current = current->next;
    }

    greater->next = nullptr;
    less->next = secondHalf.next;

    return firstHalf.next;
}

int main() {
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(4);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(2);
    head->next->next->next->next = new Node<int>(5);
    head->next->next->next->next->next = new Node<int>(2);

    int x = 3;

    Node<int> *result = partitionList(head, x);
    result->printAndFree();
}