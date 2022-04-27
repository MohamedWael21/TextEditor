/*
 * FCAI - programming 1 - 2022 - Assignment 4
 * Program Name :  mian.cpp
 * Last Modification Date : 02/4/2022
 * Author1 and ID and Group:  Mohamed Wael Mohamed      20210361    S21
 * Author2 and ID and Group:  Ali Tarek Mohamed         20210245    S21
 * Author3 and ID anf Group:  Omar Mohamed Gamal        20210270    S21
 * Teaching Assistant:  Abdulrahman Abdulmonem
 * Purpose: This is TextEditor console application
 */

// include all libraries
#include <bits/stdc++.h>
#include "function.h"

using namespace std;

// main point of  program
int main(){
    string fileName;
    cout << "Welcome to Text Editor\n";
    cout << "Please Enter File Name: ";
    cin >> fileName; // take filename from user
    
    //check if file exists or not
    fstream file{fileName, ios::in};

    if(file){
        cout << "This file is Already Exists.\n\n";
    }else{
        // create file
        file.open(fileName, ios::out);
        cout << "File " << fileName << " deos not exist. I created it for you.\n\n";
    }
    // close file
    file.close();

    // loop until user exit
    while(true){
        // show menu to user and take action according to
        takeAction(displayMenu(), fileName);
        cout << "\n";
    }

}