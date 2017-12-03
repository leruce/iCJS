//
// Created by Bidbip on 12/3/2017.
//

#ifndef CPROLOG_MAIN_H
#define CPROLOG_MAIN_H

#include <string>
#include <iostream>
using namespace std;


class Main {
public:
    static void println(string o);
    static void pp(string o);
    static void run(string fname0);
    static void srun(string fname0);
};

#endif //CPROLOG_MAIN_H
