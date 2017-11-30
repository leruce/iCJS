/*
MD KHORROM KHAN

*/


#include <iostream>
#include "ObStack.h"
#include "ObStack.cpp"

using namespace std;


void randGen(int arr[], int size)
{

    int a = 17;
    int X = 1;
    int seed ;
    cout<<"\nEnter a prime number as seed (make sure it's same as you used in Java Testing to get same output): "<<endl;
    cin>>seed;


    for(int i=0; i<10; i++)
    {
        X = (a * X + seed) % 256;
        arr[i] = X%9;
    }

}

void testPush() {
    int holder[10];
    randGen(holder,10);
    ObStack<int> *t = new ObStack<int>;
    cout << "\nTesting push......." << endl;
    if (t->isEmpty()) {
        cout << "Initially the stack size is: " << t->Obsize() << endl;
    }
    else {
        cout << "Current stack size is: " << t->Obsize() << endl;
    }
    for (int i=0; i<10; i++) {
        t->push(holder[i]);
        cout << t->peek() << " is pushed to the stack and  stack size increased to:  "<< t->Obsize() << endl;
    }
}

void testPop() {
    int holder[10];
    randGen(holder,10);
    ObStack<int> *t = new ObStack<int>;
    cout << "\nTesting pop......" << endl;
    cout << "First we pushed 10 numbers into the stack." << endl;
    for (int i=0; i<10; i++) {
        t->push(holder[i]);
    }
    for (int i=0; i<10; i++) {
        int popped = t->pop();
        cout << popped << " is popped from the stack." << endl;
    }
}

void testPeek() {
    int holder[10];
    randGen(holder,10);
    ObStack<int> *t = new ObStack<int>;
    cout << "\nTesting peep......" << endl;
    for (int i=0; i<10; i++) {
        t->push(holder[i]);
    }
    cout << "First we pushed 10 numbers into the stack and " <<holder[9]<<" is at the top of the stack."<<endl;
    int peeped = t->peek();
    cout << "We peep on the stack: " << peeped << endl;
}

//int[] pushAll(ObStack<int> t, int[] result){

  //  for (int i=0; i<t->Ob)


//}


int main() {

    testPop();
    testPeek();
    testPush();
    return 0;
}


/*
Enter a prime number as seed (make sure it's same as you used in Java Testing to get same output):
11

Testing pop......
First we pushed 10 numbers into the stack.
3 is popped from the stack.
0 is popped from the stack.
7 is popped from the stack.
1 is popped from the stack.
0 is popped from the stack.
5 is popped from the stack.
6 is popped from the stack.
8 is popped from the stack.
6 is popped from the stack.
1 is popped from the stack.

Enter a prime number as seed (make sure it's same as you used in Java Testing to get same output):
13

Testing peep......
First we pushed 10 numbers into the stack and 8 is at the top of the stack.
We peep on the stack: 8

Enter a prime number as seed (make sure it's same as you used in Java Testing to get same output):
17

Testing push.......
Initially the stack size is: 0
7 is pushed to the stack and  stack size increased to:  1
2 is pushed to the stack and  stack size increased to:  2
4 is pushed to the stack and  stack size increased to:  3
4 is pushed to the stack and  stack size increased to:  4
7 is pushed to the stack and  stack size increased to:  5
3 is pushed to the stack and  stack size increased to:  6
2 is pushed to the stack and  stack size increased to:  7
3 is pushed to the stack and  stack size increased to:  8
7 is pushed to the stack and  stack size increased to:  9
0 is pushed to the stack and  stack size increased to:  10

*/
