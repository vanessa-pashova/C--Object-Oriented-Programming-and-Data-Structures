//
// Created by Vanessa Pashova on 18.11.24.
//

#ifndef DSA_LINKEDLISTNODE_H
#define DSA_LINKEDLISTNODE_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node *next;

    Node<T>(T data) : data(data), next(nullptr) {}
};

#endif //DSA_LINKEDLISTNODE_H
