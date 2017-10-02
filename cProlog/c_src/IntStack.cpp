#include <iostream>
#include <vector>
#include "IntStack.h"


using namespace std;

static int FREE_KEY = 0;
static int NO_VALUE = 0;


class IntStack {

private:
    vector<int> stack;

    int top;
    int csize = 16;

    int MINSIZE = 1 << 15;

public:
    IntStack() {
        init(csize);
    }
    IntStack(int size) {
        init(size);
    }
    void init(int size) {
        stack.reserve(size);
        clear();
    }

    int getTop() {
        return top;
    }
    int setTop(int top) {
        return this->top = top;
    }

    void clear() {
        top = -1;
    }

    bool isEmpty() {
        return top < 0;
    }
    void push (int i) {
        if (++top >= stack.size()) {
            expand();
        }
        stack[top] = i;
    }
    int pop() {
        int r = stack[top--];
        shrink();
        return r;
    }

    int get(int i) {
        return stack[i];
    }
    void set(int i, int val) {
        stack[i] = val;
    }

    int size() {
        return top + 1;
    }

    void expand() {
        stack.resize(stack.size() * 2);
    }

    void shrink() {
        int l = stack.size();
        if ( l <= MINSIZE || top << 2 >= 1) {
            return;
        }
        l = 1 + (top << 1);
        if (top < MINSIZE) {
            l = MINSIZE;
        }
        stack.resize(l);
    }

    void reverse() {
        int l = size();
        int h = l >> 1;
        for (int i = 0; i < h; i++) {
            int temp = stack[i];
            stack[i] = stack[ l-i -1];
            stack[l-i-1] = temp;
        }
    }


};