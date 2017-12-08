#include <iostream>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"
#include "IMap.h"
#include <sstream>
#include <fstream>
#include "Toks1.h"
#include "Engine1.h"
#include "Prog.h"
#include <chrono>
#include <vector>
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;



void run(string fname0) {
    bool p = true;
    string fname = fname0 + ".nl";
    Engine1 *P;
    if (p) {
        P = new Prog(fname);
        cout << "CODE" << endl;
        ((Prog *) P)->ppCode();
    }
    else {
        P = new Engine1(fname);
    }
    cout << "RUNNING" << endl;
    //Get time
    auto start = chrono::high_resolution_clock::now();
    P->run();
    auto finish = chrono::high_resolution_clock::now();
    //Get time
    cout << "time=" << chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000000000.0<< endl;

}

int main(int argc, char *argv[]) {
    string s;
    //string fname = argv[1];
    if (argc != 2) {
        s = "add.pl";
    }
    else {
        s = argv[1];
    }
     //string s = "big.pl";
    //cout << "Get to the before run(s)" << endl;
     run(s);
    //vector<vector<vector<string>>> Wsss = Toks1::toSentence(s, true);
    //Toks1::PrintTok(Wsss);
    return 0;
}

