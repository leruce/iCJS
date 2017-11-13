#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"

using namespace std;



int main() {

    //This will be IntStack Test
    IntStack *n = new IntStack();

    if (n->isEmpty()) {
        cout << "Is Empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }
    cout << n->size();

    n->push(3);
    cout << "Current Top " << n->getTop() << endl;

    n->push(6);
    cout << "Current Top " << n->getTop() << endl;

    cout << "Index Value 1: " << n->get(1) << endl;
    cout << "Index Value 2: " << n->get(2) << endl;
    n->set(1, 5);
    cout << "Index Value 1: " << n->get(1) << endl;
    n->set(2,3);
    cout << "Index Value 2: " << n->get(2) << endl;
    cout << "Size is " << n->size() << endl;
    cout << "popped " << n->pop() << endl << endl;


    //Conductors
    IntMap *m = new IntMap();
    if (m->add(1)) {
        cout << "failed" << endl;
    }
    else {
        cout << "added" << endl;
    }

    cout <<"main size is " << m->size() << endl;
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
    if (m->contains(2)) {
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