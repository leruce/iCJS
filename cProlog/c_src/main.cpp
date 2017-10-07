#include <iostream>
#include "IntList.h"
#include "IntStack.h"

using namespace std;



int main() {
    IntStack *m = new IntStack();
    IntStack *n = new IntStack(16);
    m->push(2);
    m->push(4);

    n->push(7);
    n->push(3);

    cout << m->pop() << endl;
    cout << n->pop() << endl;

    cout << "Hello This will be our First commit for our main function" << endl;
    cout << "Hello. Practicing doing my First branch and commit" << endl;
    cout << "This is my first commit."; // added by CG
    return 0;
}