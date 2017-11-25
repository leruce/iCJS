//
// Created by COLLEEN VANDERBILT on 10/1/17.
//

#ifndef IPROLOG_INTSTACK_H
#define IPROLOG_INTSTACK_H

#include <iostream>
#include <vector>
#include <sstream>


class IntStack {
public:
  IntStack();
  IntStack(int size);
  void init(int size);
  int getTop();
  int setTop(int top);
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
  std::string toString();
  std::vector<int> toVec();

private:
  std::vector<int> stack;
  int top;
};



#endif //IPROLOG_INTSTACK_H
