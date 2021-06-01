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

            //else{
            //     newNode->next = head;
            //     head = newNode;
            // }
        }

        void printAllFriends(){
            Node* temp = head;
            while(temp != nullptr){
                std::cout << "\tName: " << temp->name << std::endl;
                temp = temp->next;
            }
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

    std::string name;
    friendLL* myFriends;
    int profileIndex;
    redBlackNode* left;
    redBlackNode* right;
};

class friendshipGraph {
    public:
        friendshipGraph() {};

        void addProfile(std::string n, redBlackNode& rbNode);
        // {
        //     graphNode newNode = graphNode(n);
        //     rbNode.graphPtr = &newNode;
        //     theGraph.push_back(newNode);
        // }

        void addFriend(std::string name1, std::string name2){
            for(int i = 0; i < theGraph.size(); i++) {
                if(theGraph[i].name == name1) {
                    theGraph[i].myFriends->newFriend(name2);
                }
                if(theGraph[i].name == name2){
                    theGraph[i].myFriends->newFriend(name1);
                }
            }
        }

        void printFriends(std::string n) {
            for(int i = 0; i < theGraph.size(); i++) {
                if(theGraph[i].name == n) {
                    std::cout << "Friends of " << n << std::endl;
                    theGraph[i].myFriends->printAllFriends();
                }
            }
        }

        void print(){
            for(int i = 0; i < theGraph.size(); i++){
                std::cout << theGraph[i].name << std::endl;
            }
        }
        
    private:
        std::vector<graphNode> theGraph;

};

#endif 