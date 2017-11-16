#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

    string str;
    int i, length;
    int flag = 0;

    cout << "Enter a string: "; cin >> str;

    length = str.length();

    for(i=0;i < length ;i++){
        if(str[i] != str[length-i-1]){
            flag = 1;
            break;
	   }
	}

    if (flag) {
        cout << str << " is not a palindrome" << endl;
    }
    else {
        cout << str << " is a palindrome" << endl;
    }

    return 0;

}


