// All defination and implmentaion Here

// include all libraries
#include <bits/stdc++.h>
#include "function.h"

using namespace std;

// show menu to user and return choice
int displayMenu(){
    int choice = 0;

    cout << "1.  Add new text to the end of the file\n";
    cout << "2.  Display the content of the file\n";
    cout << "3.  Empty the file\n";
    cout << "4.  Encrypt the file content\n";
    cout << "5.  Decrypt the file content\n";
    cout << "6.  Merge another file\n";
    cout << "7.  Count the number of words in the file\n";
    cout << "8.  Count the number of characaters in the file\n";
    cout << "9.  Count the number of Lines in the file\n";
    cout << "10. Search for word in the file\n";
    cout << "11. Count the numberof times a word exists in the file\n";
    cout << "12. Turn the file content to upper case.\n";
    cout << "13. Turn the file content to lower case.\n";
    cout << "14. Turn file content to 1st caps (1st char of each word is capital)\n";
    cout << "15. Save\n";
    cout << "16. Exit\n\n";


    cout << "Please Enter your choice ===> ";
    //validate input 
    while(!(cin >> choice) || choice > 16 || choice < 1){
        //clear any flags and discard any invalid character from buffer
        cin.clear();
        cin.ignore();

        cout << "Please Enter your choice ===> ";
    }
    
    return choice;
}

//call functions according to choice
void takeAction(int choice, string fileName){
    switch (choice){
    case 1:
        // funciton call
        break;
    
    case 16:
    
        exit(0);
        break;
    default:
        break;
    }
}
