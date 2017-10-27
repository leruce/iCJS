#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"

using namespace std;



int main() {
    //Conductors
    IntMap *m = new IntMap();
    IntMap *n = new IntMap(16);
    IntMap *z = new IntMap(16, .8f);
    //cout << "In main size" << m->size() << endl;
    if (m->add(1)) {
        cout << "failed" << endl;
    }
    else {
        cout << "added" << endl;
    }
    //cout <<"main size is " << m->size() << endl;
    if (m->add(2)) {
        cout << "failed" << endl;
    }
    else {
        cout << "added" << endl;
    }
    //cout << "main size is " << m->size() << endl;
    if (m->isEmpty()) {
        cout << "Is Empty" << endl;
    }
    else {
        cout << "Is not Empty" << endl;
    }
    if (m->contains(1)) {
        cout << "Contain Works" << endl;
    }
    else {
        cout << "Contain doesnt work" << endl;
    }
    if (m->mDelete(1)) {
        cout << "delete works" << endl;
    }
    else {
        cout << "delete doesnt work" << endl;
    }

    cout << "Done with code" << endl;
    cout << "main size is " << m->size() << endl;
    return 0;
}