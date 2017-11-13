#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"

using namespace std;



int main() {


    //This will be IntStack Test
    IntStack *m = new IntStack();
    IntStack *n = new IntStack(10);

    if (m->isEmpty()) {
        cout << "Is Empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }
    cout << m->size();

    m->push(3);
    cout << "Current Top " << m->getTop() << endl;

    m->push(6);
    cout << "Current Top " << m->getTop() << endl;

    cout << "Index Value 1: " << m->get(1) << endl;
    cout << "Index Value 2: " << m->get(2) << endl;
    m->set(1, 5);
    cout << "Index Value 1: " << m->get(1) << endl;
    m->set(2,3);
    cout << "Index Value 2: " << m->get(2) << endl;
    cout << "Size is " << m->size() << endl;
    cout << "popped " << m->pop() << endl;



/*

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
*/
    return 0;
}