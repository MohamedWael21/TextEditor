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
    cout << endl;
    return choice;
}

//call functions according to choice
void takeAction(int choice, vector<string> &fileContent, string &FileName){
    switch (choice){
    case 1:
        appendText(fileContent);
        break;
    case 2:
        diplayContent(fileContent);
        break;
    case 3:
        emptyFile(fileContent);
        break;
    case 4:
        EncryptFile(fileContent);
        break;
    case 5:
        DecryptFile(fileContent);
        break;
    case 6:
        //call function
        break;
    case 7:
        // call function
        break;
    case 8:
        //call function
        break;
    case 9:
        //call function
        break;
    case 10:
        //call function
        break;
     case 11:
        countWord(fileContent);
        break;
    case 12:
        toUpperFile(fileContent);
        break;
    case 13:
        toLowerFile(fileContent);
        break;
    case 14:
        toCapFile(fileContent);
        break;
    case 15:
        saveFile(fileContent, FileName);
        break;
    case 16:
        exit(0);
        break;
    default:
        break;
    }
    
}

void readContent(fstream &file, vector<string> &fileContent){
    string line;
    //read line by line in vector
    while(!file.eof()){
        getline(file, line);
        //add line to vector and add \n after each line
        if(!line.empty()){
            fileContent.push_back(line);
        }
    }

}

// add text to the end of the file
void appendText(vector<string>&fileContent){
    
    string appended_text{};
    cin.ignore();
    getline(cin, appended_text, '\0');
    appended_text[appended_text.size()-1] = '.';
    fileContent.push_back(appended_text);
    cin.clear();
}

// Show the content of the text on the console
void diplayContent(vector<string> &fileContent){
    
    for(string line : fileContent)
        cout << line << endl;
}

// delete the content of the file
void emptyFile(vector<string> &fileContent){
    fileContent.clear();
}

// Encrypt the file by shifting each character by one according to ASCII table
void EncryptFile(vector<string>&fileContent){
    for(int i = 0; i < fileContent.size(); i++)
        for(int j = 0; j < fileContent[i].size(); j++)
            fileContent[i][j]++;

}


// Decrypt the file
void DecryptFile(vector<string>&fileContent){
    for(int i = 0; i < fileContent.size(); i++)
        for(int j = 0; j < fileContent[i].size(); j++)
            fileContent[i][j]--;
}

// count number of time a word exists in file
void countWord(vector<string>&fileContent){
    string wordForSearch;
    cout << "Please, Enter word to search for: ";
    cin >> wordForSearch;
    
    // convert to lower
    transform(wordForSearch.begin(), wordForSearch.end(), wordForSearch.begin(), ::tolower);

    // number of times word appear
    int times = 0; 

    //loop on every line
    for(int i=0; i<fileContent.size(); i++){
        string word;

        // read word by word from line 
        stringstream lineStream(fileContent[i]);

        // loop on all word in line
        while (!lineStream.eof()){

            // read word
            lineStream >> word;

            // convert the word to lower case
            transform(word.begin(), word.end(), word.begin(), ::tolower);
        
            if(word == wordForSearch){
                times++;
            }
        }
        
    }

    // print number of times word appear
    cout << "\nThe word \"" << wordForSearch << "\" was found " << times << " times in the file\n";

}

// convert all word to upper case in file
void toUpperFile(vector<string>&fileContent){

    // loop on each line
    for(int i=0; i<fileContent.size(); i++){
        // loop on all character in line
        for(int j=0; j<fileContent[i].size(); j++){
            // check if it is charachter
            if(isalpha(fileContent[i][j])){
                //convert each character to upper
                fileContent[i][j] = toupper(fileContent[i][j]);
            }
        }
    }
}

//convert all word to lower case
void toLowerFile(vector<string>&fileContent){
    // loop on each line
    for(int i=0; i<fileContent.size(); i++){
        // loop on all character in line
        for(int j=0; j<fileContent[i].size(); j++){
            // check if it is charachter
            if(isalpha(fileContent[i][j])){
                // convert each character to lower
                fileContent[i][j] = tolower(fileContent[i][j]);
            }
        }
    }
}

// convert the begging of all word to upper case
void toCapFile(vector<string>&fileContent){

    // loop on every line
    for(int i=0; i<fileContent.size(); i++){

        stringstream lineStream(fileContent[i]);

        string word;
        // loop on every word
        while(!lineStream.eof()){

            lineStream >> word;

            // find first index of the word
            size_t indexWord = fileContent[i].find(word);

            if(isalpha(word[0])){
                // uppercase first letter
                word[0] = toupper(word[0]);
                // replace old word with new one
                fileContent[i].replace(indexWord, word.size(), word);
            }            
        }
        
    }
}

void saveFile(vector<string>&fileContent, string &oldFileName){
    string fileName;
    cout << "Enter a new file name or press enter to save on the same file ===> ";
    // remove \n from buffer
    cin.ignore();
    getline(cin, fileName);

    cout << '\n';

    // save on same file
    if(fileName.empty()){
        fstream file;
        file.open(oldFileName, ios::out);
        // loop on every line and write in same file
        for(int i=0; i<fileContent.size(); i++){
           file << fileContent[i] << '\n';
       }
       file.close();

       file.open(oldFileName, ios::in);
       fileContent.clear(); // delete any old content

       // updated filecontent
       readContent(file, fileContent);
       file.close();

    }else{ // save on different file

        // open newfile for write
        ofstream newFile(fileName);
        
        // write line by line on new file
        for(int i=0; i<fileContent.size(); i++){
            newFile << fileContent[i] << '\n';
        }

        newFile.close();
    }
    cout << "File is Saved\n";
}


void numberOfWords(vector<string>&fileContent){ //numberofwords
    // number of words in file
    int words = 0;
    // loop on every line in file
    for(int i=0; i<fileContent.size(); i++){
        stringstream lineStream(fileContent[i]);
        string word;
        //loop on each word
        while(lineStream>>word){
            words++;
        }
    }

    cout<<"number of words: "<< words << '\n';
    
}


void searchForWordInFile(vector<string>&fileContent)
{               
    string searchWord;
    cout << "Enter the word to search: ";
    cin >> searchWord;
    // conver word lo lower case
    transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

    // loop on every line
    for(int i=0; i<fileContent.size(); i++){
        stringstream lineStream(fileContent[i]);
        string word;
        // loop on every word;
        while(lineStream >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(word == searchWord){ // word found
                cout << "Word was found in File\n";
                return;
            }
        }
    }

    // word was not found 
    cout << "Word was not found in the file\n";
}

void numberOfLines(vector<string>&fileContent)
{
    cout << "Number of lines in File: " << fileContent.size() << '\n';    
}

void numberofcharters(vector<string>&fileContent)
{
    int characters = 0; // number of characters without space

    // loop on every line
    for(int i=0; i<fileContent.size(); i++){
        stringstream lineStream(fileContent[i]);
        // get every character
        while(!lineStream.eof()){
            char chr = lineStream.get();
            // not space
            if(!isspace(chr) && chr != EOF){
                characters++;
            }
        }
    }
    cout << "Number of characters (without space): " << characters << '\n';
}

void mergeOfFiles(vector<string>&fileContent)
{
  ifstream file;
  string fileName;
  cout<<"Enter file name: ";
  getline(cin,fileName);
  file.open(fileName);

  if(!file){
     cout << "Invalid File Name\n" ;
  }else{
      //read line by line from file
      string line;
      while(!file.eof()){
          getline(file, line);
          fileContent.push_back(line);
      }
  }

  file.close();
}

