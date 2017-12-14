//
// Created by Bidbip on 10/9/2017.
//

#include "Clause.h"


using namespace std;

Clause::Clause(int len, vector<int> &hgs, int base, int neck, vector<int> &xs) {
    this->hgs = hgs;
    this->base = base;
    this->len = len;
    this->neck = neck;
    this->xs = xs;
}

Clause::Clause(const Clause &copier) {
    hgs = copier.hgs;
    base = copier.base;
    len = copier.len;
    neck = copier.neck;
    xs = copier.xs;
}

Clause::~Clause() {
    xs.clear();
    hgs.clear();
}