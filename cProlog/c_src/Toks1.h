//
// Created by Bidbip on 12/4/2017.
//

#ifndef CPROLOG_TOKS1_H
#define CPROLOG_TOKS1_H

#include <string>
#include <vector>
#include <fstream>
#include "Toks1.h"
#include <boost/tokenizer.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>


using namespace std;

class Toks1 {
public:
    static string getWord(string std);
    static vector<vector<vector<string>>> toSentence(string &s, bool fromFile);
    static void PrintTok(vector<vector<vector<string>>> s);
};


#endif //CPROLOG_TOKS1_H
