#include <iostream>
#include <stack>

#include "../Structs_Ready/LinkedListNode.h"

std::stack<Node<int>*> buildStack(Node<int> *node) {
    std::stack<Node<int>*> stack;
    Node<int> *current = node;

    while(current != nullptr){
        stack.push(current);
        current = current->next;
    }

    return stack;
}

void reorderListHelper(Node<int> *node, std::stack<Node<int>*> &stack, std::size_t size) {
    Node<int> *current= node;

    for(std::size_t i = 0; i < size / 2; i++) {
        Node<int> *currentLastNode = stack.top();
        stack.pop();

        Node<int> *nextNode = current->next;

        current->next = currentLastNode;
        currentLastNode->next = nextNode;

        current = nextNode;
    }

    current->next = nullptr;
}

void reorderList(Node<int>* node) {
    if(!node || !node->next)
        return;

    std::stack<Node<int>*> stack = buildStack(node);
    reorderListHelper(node, stack, stack.size());
}

void printList(Node<int> *node) {
    Node<int> *temp = node;

    while(temp != nullptr) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }

    std::cout << '\n';
}

void freeList(Node<int> *node) {
    while(node) {
        Node<int> *temp = node;
        node = node->next;
        delete temp;
    }
}

int main() {
    Node<int> *node = new Node<int>(1);
    node->next = new Node<int>(2);
    node->next->next = new Node<int>(3);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    std::cout << "Original: ";
    printList(node);

    reorderList(node);

    std::cout << "Post: ";
    printList(node);
    freeList(node);
}