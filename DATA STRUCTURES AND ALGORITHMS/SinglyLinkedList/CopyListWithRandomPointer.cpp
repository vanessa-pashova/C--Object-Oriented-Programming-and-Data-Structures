#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next, *random;

    Node(T data) : data(data), next(nullptr), random(nullptr) {}
};

Node<int> *copyRandomList(Node<int> *node) {
    if(!node)
        return nullptr;

    Node<int> *newHead = new Node<int>(node->data);
    Node<int> *currentOriginal = node, *copy = newHead;

    //1. Copy the data and the correct "next" pointers
    while(currentOriginal) {
        Node<int> *currentOfCopy= new Node<int>(currentOriginal->next->data);
        copy->next = currentOriginal;

        copy = copy->next;
        currentOriginal = currentOfCopy->next;
    }

    //2. Copy the right "random" pointers
    currentOriginal = node, copy = newHead;
    while(currentOriginal) {
        if(currentOriginal) {
            Node<int> *tempOriginal = node, *tempCopy = newHead;

            while(tempOriginal && (tempOriginal->random != currentOriginal->random)) {
                tempOriginal = tempOriginal->next;
                tempCopy = tempCopy->next;
            }

            copy->random = tempCopy->random;
        }

        currentOriginal = currentOriginal->next;
        copy = copy->next;
    }

    return newHead;
}

void printList(Node<int> *node) {
    Node<int> *temp = node;
    while (temp) {
        std::cout << "Value: " << temp->data << '\n';
//        std::cout << "Next: " << (temp->next ? std::to_string(temp->next->data) : "nullptr") << '\n';
        std::cout << "Random: " << (temp->random ? std::to_string(temp->random->data) : "nullptr") << "\n\n";
        temp = temp->next;
    }
}

int main() {
    Node<int>* node1 = new Node<int>(7);
    Node<int>* node2 = new Node<int>(13);
    Node<int>* node3 = new Node<int>(11);
    Node<int>* node4 = new Node<int>(10);
    Node<int>* node5 = new Node<int>(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    Node<int>* copiedList = copyRandomList(node1);

    std::cout << "Original List:\n";
    printList(node1);

    std::cout << "\nCopied List:\n";
    printList(copiedList);
}