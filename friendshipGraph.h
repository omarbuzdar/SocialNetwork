#ifndef FRIENDSHIP_GRAPH_H
#define FRIENDSHIP_GRAPH_H

#include <iostream>
#include <vector>
#include "node.h"
#include "redBlackTree.h"

// class redBlack;
// struct redBlackNode;

class friendLL {
    public:
        friendLL() : head(nullptr) {}

        void newFriend(std::string person){
            Node* newNode = new Node(person);
            newNode->next = nullptr;
            Node* temp = head;
            if(head == nullptr){
                head = newNode;
            }else{
                while(temp->next != nullptr){
                    if(temp->name == person || temp->next->name == person){
                        return;
                    }
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void printAllFriends(){
            Node* temp = head;
            while(temp != nullptr){
                std::cout << "\tName: " << temp->name << std::endl;
                temp = temp->next;
            }
        }

        Node* getHead(){
            return head;
        }

        std::vector<std::string> getAllFriends(){
            std::vector<std::string> names;
            Node* temp = head;
            // if (temp == nullptr){
            //     std::cout << "temp is null" << std::endl;
            // }
            while(temp != nullptr){
                names.push_back(temp->name);
                temp = temp->next;
            }
            return names;
        }

    private:
        Node* head;
};

struct graphNode {
    graphNode(std::string n){ 
        name = n;
        myFriends = new friendLL();
        profileIndex = -1;
        left = nullptr;
        right = nullptr;
    } 

    std::vector<std::string> findFriends(){ return myFriends->getAllFriends(); }
    //     std::vector<std::string> names;
    //     Node* temp = myFriends->getHead();
    //     while(temp != nullptr){
    //         std::cout << std::endl << temp->name;
    //         names.push_back(temp->name);
    //         temp = temp->next;
    //     }
    //     return names;
    // }

    std::string name;
    friendLL* myFriends;
    int profileIndex;
    redBlackNode* left;
    redBlackNode* right;
};


class friendshipGraph {
    public:
        friendshipGraph() {};

        void addProfile(std::string n, int index, redBlackNode& rbNode);
        void addFriend(std::string name1, std::string name2);
        void printFriends(std::string n);
        void print();

        int getProfileIndex(std::string name);
        friendshipGraph* getGraph(){ return this; }
        
    private:
        std::vector<graphNode> theGraph;

};

#endif 