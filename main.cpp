#include <iostream>
#include <string>
#include "redBlackTree.h"
#include "redBlackTree.cpp"
#include "friendshipGraph.h"
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){

    redBlack rb1 = redBlack();
    friendshipGraph fg1 = friendshipGraph();
    ifstream inFile;
    string fileName = argv[1];
    inFile.open(fileName);
    if(inFile.fail()){
        cerr << "Could not open file. " << argv[1];
        exit(1);
    }
    
    string readLine;
    string name;
    ofstream outFile("profileOutput");
    
    if(inFile.is_open()){

        string thePerson;
        string age;
        string occupation;

        getline(inFile, readLine, '\n');       // get rid of 'Name,Age,Occupation,Friends'  line 1
        while(getline(inFile, readLine, '\n') && readLine != ""){
            int firstComma = readLine.find(",");
            thePerson = readLine.substr(0, firstComma);
            rb1.insert(readLine.substr(0, firstComma), fg1);    // finds the persons name
            outFile << setw(20) << thePerson;     //storing name to profileData
            
            readLine.erase(0, firstComma + 1);
            firstComma = readLine.find(",");            
            outFile << setw(3) << readLine.substr(0, firstComma);      // setting the age

            readLine.erase(0, firstComma + 1);
            firstComma = readLine.find(",");
            outFile << setw(30) << readLine.substr(0, firstComma) << endl;    //setting the job
            
            readLine.erase(0, firstComma + 2);
            firstComma = readLine.find(",\"");
            int secondComma = 0;
            while(readLine[0] != '"'){
                secondComma = readLine.find(",");
                fg1.addFriend(thePerson, readLine.substr(0, secondComma));
                readLine.erase(0, secondComma + 1);
            }
        }
    }

    //ofstream outFile;
    //outFile.open(argv[2]);
    
    inFile.close();
    outFile.close();   

    // cout << rb1.inOrder() << endl << endl;
    // fg1.printFriends("Mason Davis");
    // fg1.print();

    
    return 0;

}




// OLD STUFF IN MAIN


// for(int i = 0; i < 3; i++){
        //     getline(inFile, readLine, ',');
        // }
        // getline(inFile, readLine, '\n');
        //cout << " omar's readline\t " << readLine << endl;
        // while(getline(inFile, readLine, '\n')){
        //     string commaPos = readLine.find(",");
        //     rb1.insert(readLine, fg1);
        // }
        
        // while(!inFile.eof()){
        //     getline(inFile, readLine, ',');   // name
        //     rb1.insert(readLine, fg1);   
        //     getline(inFile, readLine, ',');   // age
        //     getline(inFile, readLine, ',');   // occupation
        //     while(getline(inFile, readLine, '\n')){
        //         getline(inFile, readLine, ',');
        //         //fg1.addFriend(readLine);
        //     }
        // }
            


            // if(!inFile.eof()) {
            //     //cout << "nicks readLine: " << readLine << endl;
            //     getline(inFile, readLine, ',');
            //     if(readLine != ""){
            //         rb1.insert(readLine, fg1);
            //         cout << "NAME: " << readLine << endl;
            //     }
            //     thePerson = readLine;
            //     getline(inFile, readLine, ',');  // age
            //     // if(readLine != ""){
            //     //     cout << "AGE: " << readLine << endl;
            //     // }
            //     getline(inFile, readLine, ',');  // occupation
            //     // if(readLine != ""){
            //     //     cout << "OCCUPATION: " << readLine << endl;
            //     // }
            //     getline(inFile, readLine, '"');  // friends
            //     cout << "READLINE FOR OMAR: " << readLine << endl;
            //     while(readLine != "\""){
            //         getline(inFile, readLine, ',');
            //         if(readLine[0] == '"'){
            //             cout << "READLINE FOR NICK: " << readLine[1] << endl;
            //             break;
            //         }
            //         if(readLine != "" && readLine != "\""){
            //             fg1.addFriend(thePerson, readLine);
            //         }
            //     }
            // }

        // for(int n = 0; n < 99; n++){
        //     getline(inFile, readLine, ',');   // name
        //     rb1.insert(readLine, fg1); 
        //     // cout << "name: " << readLine << endl;  
        //     // getline(inFile, readLine, ',');   // age
        //     // cout << "age: " << readLine << endl;
        //     // getline(inFile, readLine, ',');   // occupation
        //     // cout << "occupation: " << readLine << endl;
        //     while(getline(inFile, readLine, '\n')){
        //         getline(inFile, readLine, ',');
        //         cout << "friend: " << readLine << endl;
        //         rb1.insert(readLine, fg1);
        //         //fg1.addFriend(readLine);
        //     }
        // }
        

    // rb1.insert("omar", fg1);
    // rb1.insert("alex", fg1);
    // rb1.insert("zack", fg1);
    // rb1.insert("chris", fg1);
    // rb1.insert("steve", fg1);
    // rb1.insert("bob", fg1);
    // rb1.insert("ramon", fg1);
    // rb1.insert("peter", fg1);
    // rb1.insert("quinn", fg1);
    // rb1.insert("bz", fg1);
    // rb1.insert("zz", fg1);
    // rb1.insert("zoe", fg1);

    // fg1.addFriend("zack", "omar");
    // fg1.addFriend("chris", "zack");
    // fg1.addFriend("omar", "peter");
    // fg1.addFriend("zoe", "zack");

    // cout << rb1.inOrder() << endl;
    // fg1.print();

    // cout << "omars friends: " << endl;
    // fg1.printFriends("omar");
    // cout << "zacks friends: " << endl;
    // fg1.printFriends("zack");
    // cout << "chris friends: " << endl;
    // fg1.printFriends("chris");

    
    


    // cout << rb1.inOrder() << endl;
    // cout << rb1.countNodes(rb1.getRoot()) << endl;
    // //cout << ((rb1.search(rb1.getRoot(), "zack"))->left)->name << endl;
    // //cout << "SEARCH: " << (rb1.exactSearch(rb1.getRoot(), "zoe"))->name << endl;
    // cout <<"\n" << endl;
    // cout << "RangeQuery: \n" << rb1.rangeQuery(rb1.getRoot(), "peter", "zz") << endl;

    
    // fg1.addProfile("nick");
    // fg1.addProfile("omar");
    // fg1.addProfile("zack");
    // fg1.addProfile("martin");
    // fg1.addFriend("nick", "omar");
    // fg1.addFriend("nick", "zack");
    // fg1.addFriend("martin", "omar");
    // fg1.addFriend("martin", "nick");
    // cout << "nicks friends: " << endl;
    // fg1.printFriends("nick");
    // cout << "omars friends: " << endl;
    // fg1.printFriends("omar");
    // cout << "zacks friends: " << endl;
    // fg1.printFriends("zack");
    // cout << "martins friends: " << endl;
    // fg1.printFriends("martin");