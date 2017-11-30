/*
Garrett Addington

s.size() : 3= 3
s.get(s.getTop) : 2= 2
s.pop() : 7= 7
s.get(s.getTop) : 0= 0

Same result as the Java code.

*/

#include <iostream>
#include <vector>
#include "IntStack.h"

using namespace std;


vector<int> randomGen(int seeder) {
    vector<int> result(10);
    int a = 17;
    int X = 1;
    int seed = seeder;
    for (int i = 0; i <10; i++) {
        X = (a*X +seed) % 256;
        result[i] = X%9;
    }
    return result;
}
void testPushStack() {
    IntStack s;
    vector<int> hold = randomGen(13);
    s.push(hold[1]);
    cout << "s.get(s.getTop) : " << s.get(s.getTop()) << "= " << hold[1] << endl;
}
void testPushStackTwice() {
    IntStack s;
    vector<int> hold = randomGen(113);
    s.push(hold[1]);
    s.push(hold[2]);
    cout << "s.get(s.getTop) : " << s.get(s.getTop()) << "= " << hold[2] << endl;
}
void testPopStack() {
    IntStack s;
    vector<int> hold = randomGen(13);
    s.push(hold[3]);
    s.push(hold[4]);
    int i = s.pop();
    cout << "s.pop() : " << i << "= " << hold[4] << endl;
}
void testSize() {
    IntStack s;
    vector<int> hold = randomGen(13);
    s.push(hold[5]);
    s.push(hold[6]);
    s.push(hold[7]);
    cout << "s.size() : " << s.size() << "= 3" << endl;
}

int main() {
    testSize();
    testPushStack();
    testPopStack();
    testPushStackTwice();
    return 0;
}
