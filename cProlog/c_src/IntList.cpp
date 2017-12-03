//
// Created by COLLEEN VANDERBILT on 9/28/17.
//

#include "IntList.h"

IntList::IntList(int head) {
    this->head = head;
    this->tail = nullptr;
}

IntList::IntList(int head, IntList *xs) {
    this->head = head;
    this->tail = xs;
}

bool IntList::isEmpty(IntList *xs) {
    return (nullptr == xs);
}

int IntList::getHead(IntList *xs) {
    return xs->head;
}
IntList * IntList::getTail(IntList *xs) {
    return xs->tail;
}
IntList * IntList::cons(int x, IntList *xs) {
    if (isEmpty(xs)) {
        xs = new IntList(x);
        return xs;
    }
    else {
        return new IntList(x, xs);
    }
}
IntList * IntList::app(std::vector<int> xs, IntList *ys) {
    IntList *zs = ys;
    for (int i = xs.size() - 1; i >= 0; i--) {
        zs = cons(xs[i], zs);
    }
    return zs;
}
IntStack * IntList::toInts(IntList *Xs) {
    IntStack *is = new IntStack();
    IntList *copy = Xs;

    while (copy != nullptr) {
        is->push(copy->head);
        copy = getTail(copy);
    }
    return is;
}
int IntList::len(IntList *xs) {
    return toInts(xs)->size();
}

std::string IntList::toString() {
    return toInts(this)->toString();
}