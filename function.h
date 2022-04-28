#include <string>
#include <vector>
using namespace std;
#ifndef HEAD
#define HEAD

// all declaration and interface

int displayMenu();
void takeAction(int, string);
void readContent(ifstream&, vector<string>&);

#endif