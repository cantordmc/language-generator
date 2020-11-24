
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Markov.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }
    string filename = string(argv[1]);

    //https://www.tutorialspoint.com/Read-whole-ASCII-file-into-Cplusplus-std-string
    ifstream f("input.txt");
    string str;
    if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
   }
   if (str.length() < 5) {
       cerr << "Input text not long enough";
       return 1;
   }

    unsigned int numIterations = std::stoi (argv[2],nullptr,10);

    Markov* test = new Markov(str);
    Markov::Node* thisNode = test->getRoot();
    string thisData;
    string theReturnString = "";
    for (unsigned int i = 0; i < numIterations; i++){
        thisNode = thisNode->traverseOnce();
        if (thisNode == nullptr) thisNode = test->getRoot();
        thisData = thisNode->data;
        theReturnString.append(thisData.substr(1, 1));
    }
    cout << theReturnString << endl;
    return 0;
}
