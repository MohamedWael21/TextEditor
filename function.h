#include <string>
#include <vector>
using namespace std;
#ifndef HEAD
#define HEAD

// all declaration and interface

int displayMenu();
void takeAction(int, vector<string>&, string&);
void appendText(vector<string>&);
void diplayContent(vector<string>&);
void emptyFile(vector<string>&);
void EncryptFile(vector<string>&);
void DecryptFile(vector<string>&);
void readContent(fstream&, vector<string>&);
void countWord(vector<string>&);
void toUpperFile(vector<string>&);
void toLowerFile(vector<string>&);
void toCapFile(vector<string>&);
void saveFile(vector<string>&, string&);
void numberOfWords(vector<string>&);
void searchForWordInFile(vector<string>&);
void numberOfLines(vector<string>&);
void numberofcharters(vector<string>&);
void mergeOfFiles(vector<string>&);

#endif