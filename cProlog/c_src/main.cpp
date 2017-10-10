#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"

using namespace std;



int main() {
    IntMap *m = new IntMap();
    IntMap *n = new IntMap(16);
    m->put(0,2);
    m->put(1, 5);



    //n->add(7);
    //n->add(3);

    cout << m->size() << endl;
    cout << n->size() << endl;

    cout << "\n\nTesting IntList" << endl;
    // variables
    int var1 = 1;
    int var2 = 2;
    int var3 = 3;
    int var4 = 4;
    int var5 = 0;
    int var6 = 0;
    int numInts = -1;
    std::vector <int> vector1 = {6, 7, 8, 9};
    bool isItEmpty = false;



    IntList *list1 = new IntList(1);
    IntList *list2 = new IntList(2);
    IntList *list3 = new IntList(3);
    IntList *list4 = new IntList(4);

    isItEmpty = list1->isEmpty(*list1);
    cout << "list1 is it empty? " << isItEmpty << endl;
    isItEmpty = list2->isEmpty(*list2);
    cout << "list2 is it empty? " << isItEmpty << endl;
    isItEmpty = list3->isEmpty(*list3);
    cout << "list3 is it empty? " << isItEmpty << endl;
    isItEmpty = list4->isEmpty(*list4);
    cout << "list4 is it empty? " << isItEmpty << endl;

// testing cons
    list2 = list2->cons(var2, list2);
    isItEmpty = list2->isEmpty(*list2);
    cout << "list2 is it empty? " << isItEmpty << endl;
    list2 = list2->cons(var1, list2);
    list2 = list2->cons(var3, list2);

    var5 = list2->getHead(list2);
    cout << "var5 is now " << var5 << endl;
    list3 = list2->getTail(list2);
    numInts = list2->len(list2);
// testing app
    list4 = list2->app(vector1, list2);

// testing toInts
    list1 = (var4, list2);
    IntStack *s = new IntStack();
    s = list1->toInts(list1);



    cout << "\n\n" << endl;

    cout << "Hello This will be our First commit for our main function" << endl;
    cout << "Hello. Practicing doing my First branch and commit" << endl;
    cout << "This is my first commit."; // added by CG
    return 0;
}