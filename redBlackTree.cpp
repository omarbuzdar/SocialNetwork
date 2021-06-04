#include "redBlackTree.h"
#include "friendshipGraph.cpp"

using namespace std;


redBlackNode* redBlack::exactSearch(redBlackNode* n, std::string key){
    if (n == NULL || n->name == key){
       return n;
    }
    if (n->name < key){
       return exactSearch(n->right, key);
    }
    return exactSearch(n->left, key);
}

std::string redBlack::rangeQuery(redBlackNode* r, string name1, string name2 ){
       //vector<redBlackNode*> range; 
        return _rangeQuery(root, name1, name2);
    }

std::string redBlack::_rangeQuery(redBlackNode* r, string name1, string name2){
    std::string ret = "";
    if(r != nullptr){
        ret += _rangeQuery(r->left, name1, name2);
        if((r->name >= name1) && (r->name <= name2)){
            ret += ("NAME: " + r->name + "\n");   // r->getData()
        }
        ret += _rangeQuery(r->right, name1, name2);
        
    }
    return ret;
}

void redBlack::makeRootBlack() {
    if(root->color == "r"){
        root->color = 'b';
    }
}

int redBlack::getProfileIndex(std::string name){
    redBlackNode* temp = exactSearch(this->root, name);
    if(temp == 0){
        std::cout << "Error! Name not found!" << std::endl;
        return -1;
    }
    return temp->getIndex();
}

void redBlack::LLRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp){
    redBlackNode* temp = p->right;
    redBlackNode* GPP = gp->parent;

    bool isRight = false;
    if (gp->parent != nullptr) {
        if(gp->isRightChild()){
            isRight = true;
        }
    }

    p->right = gp;
    gp->left = temp;
    if(temp != nullptr){
        temp->parent = gp;
    }
    p->parent = gp->parent;
    gp->parent = p;
    std::string tempColor = p->color;
    p->color = gp->color;
    gp->color = tempColor;

    if(p->parent != nullptr){
        if(isRight) {
            GPP->right = p;
        }else{
            GPP->left = p;
        }
    }
    redBlackNode* tempRoot = root;
    while(tempRoot->parent != nullptr){
        tempRoot = tempRoot->parent;
    }
    root = tempRoot;
}

void redBlack::RRRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp) {
    redBlackNode* temp = p->left;
    redBlackNode* GPP = gp->parent;
    bool isRight = false;
    if (gp->parent != nullptr) {
        if(gp->isRightChild()){
            isRight = true;
        }
    }
     
    p->left = gp;
    gp->right = temp;
    if(temp != nullptr){
        temp->parent = gp;
    }

    p->parent = gp->parent;
    gp->parent = p;

    
    std::string tempColor = p->color;
    p->color = gp->color;
    gp->color = tempColor;

    if(p->parent != nullptr){
        if(isRight) {
            GPP->right = p;
        }else{
            GPP->left = p;
        }
    }
    redBlackNode* tempRoot = root;
    while(tempRoot->parent != nullptr){
        tempRoot = tempRoot->parent;
    }
    root = tempRoot;
}

void redBlack::LRRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp){
    redBlackNode* temp1 = n->left; 
    redBlackNode* temp2 = n->right;
    redBlackNode* temp3 = p->left;
    gp->left = n;
    n->left = p;
    n->parent = gp;
    p->parent = n;
    p->left = temp1;
    if(temp1 != nullptr){
        temp1->parent = p;
    }
    p->right = temp2;
    if(temp2 != nullptr){
        temp2->parent = p;
    }
    n->right = temp3;
    if(temp3 != nullptr){
        temp3->parent = n;
    }
    this->LLRotation(p, n, gp);
}

void redBlack::RLRotation(redBlackNode* n, redBlackNode* p, redBlackNode* gp){
    redBlackNode* temp1 = n->left; 
    redBlackNode* temp2 = n->right;
    redBlackNode* temp3 = p->right;
    
    gp->right = n;
    n->right = p;
    n->parent = gp;
    p->parent = n;
    p->left = temp2;
    if(temp2 != nullptr){
        temp2->parent = p;
    }
    p->right = temp3;
    if(temp3 != nullptr){
        temp3->parent = p;
    }
    n->left = temp1;
    if(temp1 != nullptr){
        temp1->parent = n;
    }

    this->RRRotation(p, n, gp);
}

redBlackNode* redBlack::insertHelper(redBlackNode* n, std::string key){
    if((n->left == nullptr && n->right == nullptr) || n->name == key)
        return n;
    if(key > n->name){
        if(n->right == nullptr){
            return n;
        }
        return this->insertHelper(n->right, key);
    }
    if(n->left == nullptr){
        return n;
    }
    return this->insertHelper(n->left, key);
}

void redBlack::insert(std::string name, int index, friendshipGraph& theG){
    redBlackNode* newNode = new redBlackNode(name);
    newNode->profileDataIndex = index;
    theG.addProfile(name, index, *newNode);
    
    newNode->color = "r";
    if(root == nullptr){
        root = newNode;
        newNode->color = "b";
        return;
    }

    // place node in correct position
    redBlackNode* temp = root;
    redBlackNode* parent = this->insertHelper(root, name);
    
    
    if(name < parent->name){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
    newNode->parent = parent; 
    

    // case 1:  parent is black

    // case 2: parent is red,two reds in row are not allowed
    
    if(parent->color == "r"){
        redBlackNode* uncle = nullptr;
        redBlackNode* gp = parent->parent;
        if(parent->isLeftChild()){
            uncle = gp->right;
        }else{
            uncle = gp->left; 
        }

        bool rotate = false;
        if(uncle == nullptr){
            rotate = true;
        }else if(uncle->color == "r"){ // uncle is red, we need to recolor
            // recolor
            rotate = false;
        }else if(uncle->color == "b") {  
            rotate = true; 
        }
        
        if(rotate){
            
            // LL Rotation
            if(parent->isLeftChild() && newNode->isLeftChild()) {
                this->LLRotation(newNode, parent, gp);
            } 
            // RR Rotation
            else if(parent->isRightChild() && newNode->isRightChild()) {
                this->RRRotation(newNode, parent, gp);
            }
            // LR Rotation
            else if(parent->isLeftChild() && newNode->isRightChild()) {
                this->LRRotation(newNode, parent, gp);
            }
            // RL Rotation
            else if(parent->isRightChild() && newNode->isLeftChild()) {
                this->RLRotation(newNode, parent, gp);                 
            }
        }else{ 
            gp->switchColor();
            parent->switchColor();
            uncle->switchColor();
            this->makeRootBlack();
        }
          
    }
}

            


redBlackNode* redBlack::getRoot(){
    return root;
}

bool redBlack::isEmpty(){
    if(root == nullptr){
        return true;
    }
    return false;
}

std::string redBlack::inOrder(){
        return _inOrder(root);
    }

std::string redBlack::_inOrder(redBlackNode* r){
    std::string ret = "";
    if(r != nullptr){
        ret += _inOrder(r->left);
        ret += ("NAME: " + r->name + "\tCOLOR: " + r->color + "\n");
        ret += _inOrder(r->right);
    }
    return ret;
}

int redBlack::countNodes(redBlackNode* r){
    if(r == nullptr){
        return 0;
    }
    int nodes = 1;
    nodes += (this->countNodes(r->left) + this->countNodes(r->right));
    return nodes;
}

void redBlack::friendshipQuery(std::string name){
    cout << "Friends of " << name << ":\n\n";
    redBlackNode* temp = exactSearch(this->root, name);
    string readLine;
    string thePerson;
    string theAge;
    string theOccupation;
    graphNode* graphPerson = temp->getGraphPointer();
    
    vector<std::string> friendsNames = graphPerson->findFriends();
    
    for(int i = 1; i <= friendsNames.size(); i++){
        ifstream theFile;
        theFile.open("profileOutput");
        int profileNum = (this->exactSearch(this->root, friendsNames[i-1]))->getIndex();
        for(int j = 1; j <= profileNum; j++){
            getline(theFile, readLine, '\n');
        }

        thePerson = readLine.substr(0, 20);
        for(int n = 0; n < readLine.size(); n++){
            if(readLine[n] != ' '){
                break;
            }
            thePerson.erase(0,1);
        }
        readLine.erase(0,20);
        theAge = readLine.substr(0,3);
        for(int n = 0; n < readLine.size(); n++){
            if(readLine[n] != ' '){
                break;
            }
            theAge.erase(0,1);
        }
        readLine.erase(0,3);
        theOccupation = readLine;
        for(int n = 0; n < readLine.size(); n++){
            if(readLine[n] != ' '){
                break;
            }
            theOccupation.erase(0,1);
        }

        cout << "\tFriend " << i << ": " << thePerson << " \n\t\t  Age: " << theAge << "\n\t\t  Occupation: " << theOccupation << endl << endl;  

        theFile.close();
    }
}