// #include "redBlackTree.h"
#include "friendshipGraph.h"


void friendshipGraph::addProfile(std::string n, int index, redBlackNode& rbNode){
    graphNode* newNode = new graphNode(n);
    newNode->profileIndex = index;
    rbNode.graphPtr = newNode;
    newNode->left = rbNode.left;
    newNode->right = rbNode.right;
    theGraph.push_back(*newNode);
}

void friendshipGraph::addFriend(std::string name1, std::string name2){
    for(int i = 0; i < theGraph.size(); i++) {
        if(theGraph[i].name == name1) {
            theGraph[i].myFriends->newFriend(name2);
        }
        if(theGraph[i].name == name2){
            theGraph[i].myFriends->newFriend(name1);
        }
    }
}

void friendshipGraph::printFriends(std::string n) {
    for(int i = 0; i < theGraph.size(); i++) {
        if(theGraph[i].name == n) {
            std::cout << "Friends of " << n << std::endl;
            theGraph[i].myFriends->printAllFriends();
        }
    }
}

void friendshipGraph::print(){
    for(int i = 0; i < theGraph.size(); i++){
        std::cout << theGraph[i].name << std::endl;
    }
}

int friendshipGraph::getProfileIndex(std::string name){
    for(int i = 0; i < theGraph.size(); i++) {
        if(theGraph[i].name == name) {
            return theGraph[i].profileIndex;
        }
    }
    std::cout << "Error! Name not found!" << std::endl;
    return -1;
}