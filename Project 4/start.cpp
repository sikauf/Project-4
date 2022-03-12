/**
 * Copyright 2020 University of Michigan EECS183
 *
 * start.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <iostream>
#include <string>

using namespace std;

//********************************************************
// Function declarations. 
// Function definitions are in battleship.cpp and test.cpp
//********************************************************
void battleship();
void startTests();

int main() {
    
    cout << "-------------------------------" << endl
         << "EECS 183 Project 4 Menu Options" << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute battleship() function to play game" << endl;    
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1) {
        startTests();
    }
    else if (choice == 2) {
        battleship();
    }
    
    return 0;
}
