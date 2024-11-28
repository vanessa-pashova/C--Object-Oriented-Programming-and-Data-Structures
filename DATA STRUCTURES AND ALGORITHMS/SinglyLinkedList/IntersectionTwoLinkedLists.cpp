#include <iostream>
#include "../Structs_Ready/LinkedListNode.h"

std::size_t sizeOfNodes(Node<int> *node) {
    std::size_t counter = 0;
    while(node) {
        counter++;
        node = node->next;
    }
    return counter;
}

int intersection(Node<int> *node1, Node<int> *node2) {
    std::size_t size1 = sizeOfNodes(node1), size2 = sizeOfNodes(node2),
            diff = std::abs((int)size1 - (int)size2);

    Node<int> *current1 = node1, *current2 = node2;

    if(size1 < size2) {
        while(diff != 0) {
            current2 = current2->next;
            diff--;
        }
    }

    else if(size1 > size2) {
        while(diff != 0) {
            current1 = current1->next;
            diff--;
        }
    }

    while(current1 && current2) {
        if(current1 == current2)
            return current1->data;

        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}

int main() {
    Node<int> *node = new Node<int>(4);
    node->next = new Node<int>(1);
    node->next->next = new Node<int>(8);
    node->next->next->next = new Node<int>(4);
    node->next->next->next->next = new Node<int>(5);

    Node<int> *node2 = new Node<int>(5);
    node2->next = new Node<int>(6);
    node2->next->next = new Node<int>(1);
    node2->next->next->next = node->next->next;

    int result = intersection(node, node2);

    if (result != -1)
        std::cout << "Intersection at node with value: " << result << '\n';
    else
        std::cout << "No intersection found.\n";

    return 0;
}
