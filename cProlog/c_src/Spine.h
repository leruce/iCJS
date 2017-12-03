//
// Created by Bidbip on 10/9/2017.
//

#ifndef CPROLOG_SPINE_H
#define CPROLOG_SPINE_H
#include <iostream>
#include <vector>
#include "IntList.h"

using namespace std;

class Spine {
public:
    Spine(vector<int> gs0, int base, IntList *gs, int ttop, int k, vector<int> cs);
    Spine(int hd, int ttop);
    int hd;
    int base;
    IntList *gs;
    int ttop;
    int k;
    vector<int> xs;
    vector<int> cs;
};


#endif //CPROLOG_SPINE_H
