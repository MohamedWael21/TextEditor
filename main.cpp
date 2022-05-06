/*
 * FCAI - programming 1 - 2022 - Assignment 4
 * Program Name :  main.cpp
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

// main point of program
int main(){
    string fileName;
    cout << "Welcome to Text Editor\n";
    cout << "Please Enter File Name with the extension: ";
    cin >> fileName; // take filename from user
    
    //open file for read and write
    fstream file;
    file.open(fileName);

    //check if file exists or not
    if(file){
        cout << "This file is Already Exists.\n\n";
    }else{
        // create file
        file.open(fileName, ios::out);
        cout << "File " << fileName << " deos not exist. I created it for you.\n\n";
    }
 
    //content of file 
    vector<string>fileContent;

    //read file content in vector
    readContent(file, fileContent);
    
    // loop until user exit
    while(true){
        // show menu to user and take action according to
        takeAction(displayMenu(), fileContent, fileName);
        cout << "\n";
    }

    file.close();

}