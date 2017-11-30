/* Garrett Addington
Element in list are: [ 2, 3 ]
Element in list are: [ 3, 2, 2, 4, 7, 7, 4, 7, 7, 8 ]
Head is: 4
Tail is: [ 1, 0, 2, 2, 4, 0, 3, 4, 3 ]
*/
#include "IntList.h"
#include <iostream>
#include <vector>

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

void testCons() {
    vector<int> hold = randomGen(13);
    IntList *L1 = IntList::empty;
    IntList *L2 = IntList::cons(hold[0], L1);
    IntList *L3 = IntList::cons(hold[1], L2);
    cout << "Element in list are: " << L3->toString() << endl;
}
void testApp() {
    vector<int> hold = randomGen(13);
    IntList *L1 = IntList::empty;
    IntList *L2 = IntList::app(hold, L1);
    cout << "Element in list are: " << L2->toString() << endl;
}
void testHead() {
    vector<int> hold = randomGen(113);
    IntList *L1 = IntList::empty;
    IntList *L2 = IntList::app(hold, L1);
    cout << "Head is: " << IntList::getHead(L2) << endl;
    cout << "Tail is: " << (IntList::getTail(L2))->toString() << endl;
}
int main() {
    testCons();
    testApp();
    testHead();
    return 0;
}
