#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

bool isPalindrome(Node<int> *node) {
    Node<int> *slow = node, *fast = node;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<int> *prev = nullptr, *current = slow;
    while(current) {
        Node<int> *nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }

    Node<int> *firstHalf = node, *secondHalf = prev;
    while(firstHalf && secondHalf) {
        if(firstHalf->data != secondHalf->data)
            return false;

        else {
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
    }

    return true;
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(2);
    node->next->next->next = new Node<int>(1);

    std::cout << (isPalindrome(node) ? "node is palindrome" : "node is not palindrome");
    std::cout << '\n';

    Node<int> *head = new Node<int>(0);
    head->next = new Node<int>(1);
    head->next->next = new Node<int>(2);

    std::cout << (isPalindrome(head) ? "head is palindrome" : "head is not palindrome");

    while(node) {
        Node<int> *temp = node;
        node = node->next;
        delete temp;
    }

    while(head) {
        Node<int> *temp2 = head;
        head = head->next;
        delete temp2;
    }
}