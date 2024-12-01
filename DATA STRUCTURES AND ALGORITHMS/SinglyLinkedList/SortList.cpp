#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

Node<int> *findMiddle(Node<int> *head) {
    if(!head || !head->next)
        return head;

    Node<int> *fast = head->next, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node<int> *merge(Node<int> *left, Node<int> *right) {
    if(!left)
        return right;

    if(!right)
        return left;

    Node<int> dummy(0);
    Node<int> *tail = &dummy;

    while(left && right) {
        if(left->data < right->data) {
            tail->next = left;
            left = left->next;
        }

        else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    tail->next = left ? left : right;
    return dummy.next;
}

Node<int> *mergeSort(Node<int> *head) {
    if(!head || !head->next)
        return head;

    Node<int> *middle = findMiddle(head);
    Node<int> *rightHalf = middle->next;
    middle->next = nullptr;

    Node<int> *leftSorted = mergeSort(head);
    Node<int> *rightSorted = mergeSort(rightHalf);

    return merge(leftSorted, rightSorted);
}

int main() {
    Node<int> *node = new Node<int>(4);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(1);
    node->next->next->next = new Node<int>(3);

    Node<int> *sorted = mergeSort(node);
    sorted->printAndFree();
}
