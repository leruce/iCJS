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

    cout << "Hello This will be our First commit for our main function" << endl;
    cout << "Hello. Practicing doing my First branch and commit" << endl;
    cout << "This is my first commit."; // added by CG
    return 0;
}