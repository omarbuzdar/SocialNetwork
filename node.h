#ifndef NODE_H
#define NODE_H

#include <string>
struct Node {
    Node(std::string person) : name(person), next(nullptr) {}
    std::string name;
    Node* next;
};

#endif