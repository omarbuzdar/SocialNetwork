// #include "redBlackTree.h"
#include "friendshipGraph.h"


void friendshipGraph::addProfile(std::string n, redBlackNode& rbNode){
    graphNode newNode = graphNode(n);
    rbNode.graphPtr = &newNode;
    newNode.left = rbNode.left;
    newNode.right = rbNode.right;
    theGraph.push_back(newNode);
}