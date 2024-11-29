#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *addition(Node<int> *&node1, Node<int> *&node2) {
    Node<int> *dummy = new Node<int>(0); //Фиктивен
    Node<int> *tail = dummy;
    int carry = 0;

    while(node1 || node2 || carry) {
        int sum = carry;

        if(node1) {
            sum += node1->data;
            node1 = node1->next;
        }

        if(node2) {
            sum += node2->data;
            node2 = node2->next;
        }

        carry = sum / 10;
        tail->next = new Node<int>(sum % 10);
        tail = tail->next;
    }

    Node<int> *result = dummy->next;
    delete dummy;
    return result;
}

int main() {
    Node<int> *node1 = new Node<int>(2);
    node1->next = new Node<int>(4);
    node1->next->next = new Node<int>(3);

    Node<int> *node2 = new Node<int>(5);
    node2->next = new Node<int>(6);
    node2->next->next = new Node<int>(4);

    Node<int> *result = addition(node1, node2);
    result->printAndFree();

    node1->printAndFree();
    node2->printAndFree();
}
