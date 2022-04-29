#include <string>
#include <vector>
using namespace std;
#ifndef HEAD
#define HEAD

// all declaration and interface

int displayMenu();
void takeAction(int, vector<string>&, string&);
void readContent(fstream&, vector<string>&);
void countWord(vector<string>&);
void toUpperFile(vector<string>&);
void toLowerFile(vector<string>&);
void toCapFile(vector<string>&);
void saveFile(vector<string>&, string&);

#endif