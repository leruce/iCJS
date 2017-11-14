//
// Created by Bidbip on 11/13/2017.
//

#ifndef OBSTACKTEST_OBSTACK_H
#define OBSTACKTEST_OBSTACK_H
#include <vector>

using namespace std;

template <class T>
class ObStack {
private:
    vector<T> *t;

public:
    ObStack();
    T pop();
    void push(T O);
    T peek();
    bool isEmpty();
    int Obsize();
};


#endif //OBSTACKTEST_OBSTACK_H
