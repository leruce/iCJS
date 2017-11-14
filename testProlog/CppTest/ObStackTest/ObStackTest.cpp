/*
Garrett Addington

Output:
Testing pop......
First we pushed 10 into the stack.
10 is popped from the stack.

Testing peep......
First we pushed 10 into the stack.
We peep on the stack: 10

Testing push.......
Initially the stack size is: 0
12 is pushed to the stack and  stack size increased to:  1

Exact same as the java file.

*/

#include <iostream>
#include "ObStack.h"

using namespace std;

void testPush() {
    ObStack<int> *t = new ObStack<int>;
    cout << "Testing push......." << endl;
    if (t->isEmpty()) {
        cout << "Initially the stack size is: " << t->Obsize() << endl;
    }
    else {
        cout << "Current stack size is: " << t->Obsize() << endl;
    }
    t->push(12);
    cout << t->peek() << " is pushed to the stack and  stack size increased to:  "<< t->Obsize() << endl << endl;
}

void testPop() {
    ObStack<int> *t = new ObStack<int>;
    cout << "Testing pop......" << endl;
    cout << "First we pushed 10 into the stack." << endl;
    t->push(10);
    int popped = t->pop();
    cout << popped << " is popped from the stack." << endl << endl;
}

void testPeek() {
    ObStack<int> *t = new ObStack<int>;
    cout << "Testing peep......" << endl;
    cout << "First we pushed 10 into the stack." << endl;
    t->push(10);
    int peeped = t->peek();
    cout << "We peep on the stack: " << peeped << endl << endl;
}


int main() {
    testPop();
    testPeek();
    testPush();
    return 0;
}
/*Testing pop......
First we pushed 10 into the stack.
10 is popped from the stack.

Testing peep......
First we pushed 10 into the stack.
We peep on the stack: 10

Testing push.......
Initially the stack size is: 0
12 is pushed to the stack and  stack size increased to:  1
 */
