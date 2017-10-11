//
// Created by Bidbip on 10/9/2017.
//

#include "Spine.h"

using namespace std;


Spine::Spine(vector<int> gs0, int base, IntList gs, int ttop, int k, vector<int> cs){
    hd = gs0[0];
    this->base = base;
    //Finish this later
    this->gs = IntList::getTail(IntList::app(gs0, &gs));
    this->ttop = ttop;
    this->k = k;
    this->cs = cs;
}

Spine::Spine(int hd, int ttop) {
    this->hd = hd;
    base = 0;
    //Finish This Later.
    gs = nullptr;
    this->ttop = ttop;
    k= -1;
    cs.empty();
}