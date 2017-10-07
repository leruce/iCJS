//
// Created by COLLEEN VANDERBILT on 10/1/17.
//

#ifndef IPROLOG_INTSTACK_H
#define IPROLOG_INTSTACK_H

#include <iostream>
#include <vector>


class IntStack {
public:
  IntStack();
  IntStack(int size);
  void init(int size);
  int getTop();
  int setTop();
  void clear();
  bool isEmpty();
  void push(int i);
  int pop();
  int get(int i);
  void set(int i, int val);
  int size();
  void expand();
  void shrink();
  void reverse();


private:
  vector<int> stack;
  int top;
};



#endif //IPROLOG_INTSTACK_H
