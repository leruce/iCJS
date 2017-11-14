//
// Created by Bidbip on 11/13/2017.
//

#include "ObStack.h"

template <class T>
ObStack<T>::ObStack() {
    t = new vector<T>;
}

template <class T>
T ObStack<T>::peek() {
    return t->back();
}

template <class T>
void ObStack<T>::push(T O) {
    t->push_back(O);
}

template <class T>
T ObStack<T>::pop() {
    T td = t->back();
    t->pop_back();
    return td;
}

template <class T>
bool ObStack<T>::isEmpty(){
    return ( 0 == t->size());
}

template <class T>
int ObStack<T>::Obsize(){
    t->size();
}

template class ObStack<int>;
//Need to add spine