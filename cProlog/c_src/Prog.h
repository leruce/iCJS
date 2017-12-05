//
// Created by Bidbip on 12/3/2017.
//

#ifndef CPROLOG_PROG_H
#define CPROLOG_PROG_H


#include "Engine1.h"

class Prog : public Engine1 {
public:
    Prog(string fname);
    static void pp(string O);
    static void println(string O);
    string showTerm(ObjectE O);
    static string maybeNull(ObjectE O);

    template<typename T>
    static bool isListCons(T name);

    static bool isOp(ObjectE name);
    static string st0(ObjectE args);
    void ppCode();
    string showClause(Clause s);
    void ppc(Spine S);
    void ppGoals(IntList bs);
};


#endif //CPROLOG_PROG_H
