#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>

class friendLL;
struct graphNode;
class friendshipGraph;


struct redBlackNode {
    redBlackNode(std::string n) : name(n), graphPtr(nullptr), left(nullptr), right(nullptr), parent(nullptr) {}
    std::string name;
    int profileDataIndex;
    graphNode* graphPtr;
    std::string color;
    redBlackNode* left;
    redBlackNode* right;
    redBlackNode* parent;


    bool hasLeftChild(){
        if(left == nullptr){
            return false;
        }
        return true;
    }

    bool hasRightChild(){
        if(right == nullptr){
            return false;
        } 
        return true;
    
    }
    bool isLeftChild(){
        if(name > parent->name){
            return false;
        }
        return true;
    }

    bool isRightChild(){
        if(name < parent->name){
            return false;
        }
        return true;
    }

    void switchColor(){
        if(this->color == "b"){
            this->color = "r";
        }else{
            this->color = "b";
        }
    }

    int getIndex(){
        return profileDataIndex;
    }

    graphNode* getGraphPointer(){
        return graphPtr;
    }
};


class redBlack {
    public:
        redBlack() : root(nullptr) {}

        void insert(std::string name, int index, friendshipGraph& theG);    
        
        redBlackNode* exactSearch(redBlackNode* n, std::string key);

        redBlackNode* getRoot();
        bool isEmpty();
        void makeRootBlack();
        void printAll();
        std::string _inOrder(redBlackNode* r);
        int countNodes(redBlackNode* r);

        redBlackNode* insertHelper(redBlackNode* n, std::string key);
        int getProfileIndex(std::string name);

        void LLRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp);
        void RRRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp);
        void LRRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp);
        void RLRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp);

        std::string queryPrint(std::string n, std::string type);
        void friendshipQuery(std::string name);
        void rangeQuery(redBlackNode* r, std::string name1, std::string name2);
        std::string _rangeQuery(redBlackNode* r, std::string name1, std::string name2);
        
    private:
        redBlackNode* root;
};


#endif