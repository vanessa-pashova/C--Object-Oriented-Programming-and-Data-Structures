#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

bool hasCycle(Node<int> *node) {
    if(!node || !node->next)
        return false;

    Node<int> *slow = node, *fast = node;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}

int main() {
    Node<int>* l1 = new Node<int>(3);
    l1->next = new Node<int>(2);
    l1->next->next = new Node<int>(0);
    l1->next->next->next = new Node<int>(-4);
    l1->next->next->next->next = l1->next;

    std::cout << (hasCycle(l1) ? "has cycle" : "does not has cycle") << '\n';

//    while(l1) {
//        Node<int> *temp = l1;
//        l1 = l1->next;
//        delete temp;
//    }
}