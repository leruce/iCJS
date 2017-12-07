//
// Created by Bidbip on 12/3/2017.
//

#ifndef CPROLOG_PROG_H
#define CPROLOG_PROG_H


#include "Engine1.h"

class Prog : public Engine1 {
public:
    explicit Prog(const string &fname);
    //void showTerm(int i);
    static string maybeNull(ObjectE O);
    template<typename T>
    static bool isListCons(T name);
    template <typename T>
    static bool isOp(T name);
    static string st0(ObjectE args);
    void ppCode();
    void showClause(Clause s);
    void ppc(Spine S);
    void ppGoals(IntList *bs);
};


#endif //CPROLOG_PROG_H
