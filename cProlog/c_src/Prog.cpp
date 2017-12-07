//
// Created by Bidbip on 12/3/2017.
//

#include "Prog.h"
#include "Engine1.h"

Prog::Prog(const string &fname) : Engine1::Engine1(fname){

}

template <typename T>
bool Prog::isListCons(T name) {
    return ((name.compare(".") == 0) || (name.compare("[|]") == 0) || (name.compare("list") == 0));
}

template <typename T>
bool Prog::isOp(T name) {
    return ("/" == name || "-" == name || "+" == name || "=" == name);
}


void Prog::ppCode() {
    cout << "\nSYMS:" << endl;
    //This is to output syms
    cout << "{";
    int d = 0;
    for (auto i = slist.begin(); i != slist.end(); i++) {
        //Here we output Map; TO-DO
        if (next(i) != slist.end()) {
            cout << *i << "=" << d << ",";
        }
        else {
            cout << *i << "=" << d;
        }
        d++;

    }
    cout << "}" << endl;
    //Need to Write an output Syms
    cout << "\nCLAUSES:\n" << endl;
    for (int i = 0; i < clauses.size(); i++) {
        Clause C = (clauses[i]);
        cout << "[" << i << "]:";
        showClause(C);
        cout << endl;
        //cout << showClause(C) << endl;
    }
    cout << " " << endl;
}

void Prog::showClause(Clause s) {
    string str = "";
    int l = s.hgs.size();
    str += "---base:[";
    str += to_string(s.base);
    str += "] neck: ";
    str += to_string(s.neck);
    str += "-----\n";
    str += showCells(s.base, s.len);
    //cout << str << endl;
    str += "\n";
    str += showCell(s.hgs[0]);
    str += " :- [";
    for (int i = 1; i < l; i++ ) {
        int e = s.hgs[i];
        str += showCell(e);
        if (i < l - 1) {
            str += ", ";
        }
    }
    str += "]\n";
    cout << str;
    //str += showTerm(s.hgs[0]);
    showTerm(s.hgs[0]);
    str = "";
    if (l > 1) {
        str += " :- \n";
        for (int i = 1; i <l; i++) {
            int e = s.hgs[i];
            str += "  ";
            cout << str;
            showTerm(e);
            cout << endl;
            //str += showTerm(e);
            str = "";
            //str += "\n";
        }
    }
    else {
        str += "\n";
        cout << str;
    }
    //return str;
}

/*void Prog::showTerm(int i) {
    cout << i;
}
 */

void Prog::ppGoals(IntList *bs) {
    while(!IntList::isEmpty(bs)) {
        showTerm(IntList::getHead(bs));
        //cout << showTerm(IntList::getHead(bs)) << endl;
        cout << endl;
        bs = IntList::getTail(bs);
    }
}

void Prog::ppc(Spine S) {
    IntList *bs = S.gs;
    cout << "\nppc: t=" << S.ttop << ", k=" << S.k << "len=" << IntList::len(bs) << endl;
    ppGoals(bs);
}