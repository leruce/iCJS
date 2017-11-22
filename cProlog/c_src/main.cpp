#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"
#include "IMap.h"
#include <boost/variant.hpp>

using namespace std;


boost::variant<int, vector<int>> checkfunc(int x) {
    boost::variant<int, vector<int>> a;
    if (x == 0) {
        a = 3.0;
    }
    else {
        a = vector<int>();
    }
    return a;
};

int main() {
    boost::variant<int, vector<int>> a = checkfunc(2);
    //http://www.bnikolic.co.uk/boostqf/variant.html
    cout << a << endl;

    //vector<IMap> x = IMap::create(4);
    //IMap::put(x, 0, 1, 100);
    //IMap::put(x, 1, 2, 200);
    //IMap::put(x, 2, 3, 400);
    /*
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
*/
    return 0;
}