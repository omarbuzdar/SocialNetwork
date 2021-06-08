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

    int profileDataIndex = 1;
    
    if(inFile.is_open()){

        string thePerson;
        string age;
        string occupation;

        getline(inFile, readLine, '\n');       // get rid of 'Name,Age,Occupation,Friends'  line 1
        while(getline(inFile, readLine, '\n') && readLine != ""){
            int firstComma = readLine.find(",");
            thePerson = readLine.substr(0, firstComma);
            rb1.insert(readLine.substr(0, firstComma), profileDataIndex, fg1);    // finds the persons name
            outFile << setw(20) << thePerson;     //storing name to profileData
            
            readLine.erase(0, firstComma + 1);
            firstComma = readLine.find(",");            
            outFile << setw(3) << readLine.substr(0, firstComma);      // setting the age

            readLine.erase(0, firstComma + 1);
            firstComma = readLine.find(",");
            outFile << setw(30) << readLine.substr(0, firstComma) << endl;    //setting the job
            
            
            if(readLine.find(",\"") != std::string::npos) {
                readLine.erase(0, firstComma + 2);
                firstComma = readLine.find(",\"");
                int secondComma = 0;
                while(readLine[0] != '"'){
                    secondComma = readLine.find(",");
                    fg1.addFriend(thePerson, readLine.substr(0, secondComma));
                    readLine.erase(0, secondComma + 1);
                }
            }
            
            profileDataIndex += 1;
        }

    }



    //ofstream outFile;
    //outFile.open(argv[2]);
    
      

    // cout << rb1.inOrder() << endl << endl;
    // fg1.printFriends("Mason Davis");
    // fg1.print();

    // cout << "PROFILE INDEX TEST: " << rb1.getProfileIndex("Omar Buzdar") << endl;
    //rb1.friendshipQuery("Sandra Perez");
    //cout << "-------------------" << endl;
    //rb1.rangeQuery(rb1.getRoot(), "Kendra Benson", "Kevin Young");
    //rb1.printAll();

    int option = 10;

    
    while (option != 7){
        cout << "Welcome to the pennyPlace Network ..."<< endl;
        cout << "1) Initiate a Point Query." << endl;
        cout << "2) Initiate a Range Query." << endl;
        cout << "3) Insert a New User Into the Network." << endl;
        cout << "4) Initiate a Friend Query." << endl;
        cout << "5) Establish a Friendship Relationship." << endl;
        cout << "6) See the Network." << endl;
        cout << "7) Log Out." << endl;
        cout << "Get Started Now! What do you want to do? (1,2,3,4,5,6,7):\n";
        cin >> option;
    
       if(option == 1)
       {
            string name;
            cout << "Who would you like to find? ";
            cin.ignore();
            getline(std::cin,name);
            cout << rb1.queryPrint(name, "exact");   //prints the name, age, and occupation of a given name
       }
       else if(option == 2)
       {
            string name1, name2;
            cout << "Who does the range query start from? ";
            cin.ignore();
            getline(std::cin,name1);
            cout << "Who does the range query end on? ";
            getline(std::cin,name2);
            //cin.ignore();
            rb1.rangeQuery(rb1.getRoot(), name1, name2);   //prints the name, age, and occupation of a given name
       }
       else if(option == 3)
       {
            string newInsert;
            cout << "Who would you like to insert? ";
            cin.ignore();
            getline(std::cin,newInsert);
            int firstComma = newInsert.find(",");
            string thePerson = newInsert.substr(0, firstComma);

            rb1.insert(thePerson, profileDataIndex, fg1);

            outFile << setw(20) << thePerson;
            newInsert.erase(0, firstComma + 1);
            firstComma = newInsert.find(",");   
            outFile << setw(3) << newInsert.substr(0, firstComma);      // setting the age
            newInsert.erase(0, firstComma + 1);
            outFile << setw(30) << newInsert << endl;
            profileDataIndex += 1;
       }
       else if (option == 4)
       {
            string name;
            cout << "Whose friends are we looking for? ";
            cin.ignore();
            getline(std::cin,name);
            rb1.friendshipQuery(name);
       }
       else if (option == 5)
       {
            string name1, name2;
            cout << "Who is Friend 1? ";
            cin.ignore();
            getline(std::cin,name1);
            cout << "Who if Friend 2? ";
            getline(std::cin,name2);
            fg1.addFriend(name1, name2);
       }
       else if (option == 6)
       {
           cout << "Showing all users in the network!" << endl;
           rb1.printAll();
      }
       else if (option == 7)
       {
           cout << "See you soon!" << endl;
           break;
       }
       else {
           cout << "You fkd up!" << endl;
       }

    }
    
    inFile.close();
    outFile.close(); 
    return 0;

}


   