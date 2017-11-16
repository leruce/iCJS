#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    char inFile[15];

    ifstream Input;
    cout<<"Enter the filename: ";
    cin>>inFile;
    Input.open(inFile);

    string str;
    int i, length;
    int flag = 0;

    cout<<"Following words are palindrome: "<<endl;
    while(getline(Input,str)){

            if (str == string(str.rbegin(), str.rend())) {
            cout << str<<endl;
        }
}
    return 0;

}
