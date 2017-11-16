#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main(int argc, char **argv) {
    //cout << "First Commit in the Question 2." << endl;
    string inFile;
    if (argc = 2 ) {
        inFile = argv[1];   
    }
    else {
    
    }
    ifstream Input;
    Input.open(inFile);
    string str;
    while (getline(Input,str)) {
        //Each Line have 1 word.
        if (str == string(str.rbegin(), str.rend())) {
            cout << input << "is a palindrome!" << endl;   
        }
    }
    
    return 0;
}
