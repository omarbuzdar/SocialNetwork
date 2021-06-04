#ifndef NODE_H
#define NODE_H

#include <string>
struct Node {
    Node(std::string person) : name(person), profileIndex(0), next(nullptr) {}
    std::string name;
    int profileIndex;
    Node* next;
};

#endif