#include "IntStack.h"

using namespace std;

static int mSIZE = 16;
static int MINSIZE = 1<<15;


IntStack::IntStack() {
  init(mSIZE);
}

IntStack::IntStack(int size) {
  init(size);
}

void IntStack::init(int size) {
  stack.resize(size);
  clear();
}


int IntStack::getTop() {
  return top;
}

int IntStack::setTop(int top) {
  return this->top = top;
}

void IntStack::clear() {
  top = -1;
}

bool IntStack::isEmpty() {
  return top < 0;
}

void IntStack::push(int i) {
  if (++top >= stack.size()) {
      expand();
  }
  stack[top] = i;
}

int IntStack::pop() {
  int r = stack[top--];
  shrink();
  return r;
}

int IntStack::get(int i) {
  return stack[i];
}

void IntStack::set(int i, int val) {
  stack[i] = val;
}

int IntStack::size() {
  return top + 1;
}

void IntStack::expand() {
  stack.resize(stack.size() * 2);
}

void IntStack::shrink() {
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

void IntStack::reverse() {
  int l = size();
  int h = l >> 1;
  for (int i = 0; i < h; i++) {
      int temp = stack[i];
      stack[i] = stack[ l-i -1];
      stack[l-i-1] = temp;
  }
}
std::vector<int> IntStack::toVec() {
    std::vector<int> rVec(stack);
    return rVec;
}

string IntStack::toString() {
    string str;
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < size(); ++i) {
        if (i != 0) {
            ss << ", ";
        }
        ss << stack[i];
    }
    ss << " ]";
    return ss.str();
}