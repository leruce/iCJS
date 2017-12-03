//
// Created by Bidbip on 12/2/2017.
//

#ifndef CPROLOG_ENGINE1_H
#define CPROLOG_ENGINE1_H

#include <iostream>
#include <string>
#include <vector>
#include "IntList.h"
#include "IntStack.h"
#include "IntMap.h"
#include "IMap.h"
#include "Spine.h"
#include "Clause.h"
#include "Toks.h"
#include <map>
#include <sstream>
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>
#include <cmath>

using namespace std;

class Engine1 {
public:
    static constexpr int MAXIND = 3;
    static constexpr int START_INDEX = 20;
    explicit Engine1(string fname); //Rename when remove old code
    vector<Clause> clauses;
    vector<int> cls;
    map<string, int> *syms;
    vector<string> *slist;
    static constexpr int MINSIZE = 1 << 15;
    Spine *query;
    vector<IMap> imaps;
    vector<IntMap> vmaps;
    int size();
    vector<Clause> dload(string s);

    int getRef(int x);
    virtual string showTerm(int x);
    typedef boost::make_recursive_variant<string, int, vector<boost::recursive_variant_ > >::type ObjectE;
    virtual string showTerm(ObjectE O);
    void ppTrail();
    ObjectE exportTerm(int x);
    static vector<int> getSpine(vector<int> cs);
    string showCell(int w);
    string showCells(int base, int len);
    string showCells(vector<int> cs);
    virtual void ppc(Spine C);
    virtual void ppGoal(IntList gs);
    virtual void ppSpine();
    Clause putClause(vector<int> cs, vector<int> gs, int neck);
    Clause getQuery();
    Spine * init();
    Spine * yield();
    ObjectE ask();
    void run();
    static vector<IntMap> vcreate(int l);
    static void put(vector<IMap> imaps, vector<IntMap> vss, vector<int> keys, int val);
    vector<IMap> index(vector<Clause> clauses, vector<IntMap> vmaps);

private:
    vector<int> heap;
    int top;
    IntStack *trail;
    IntStack *ustack;
    vector<Spine> spines;
    static constexpr int V = 0;
    static constexpr int U = 1;
    static constexpr int R = 2;
    static constexpr int C = 3;
    static constexpr int N = 4;
    static constexpr int A = 5;
    // G - ground?
    static constexpr int BAD = 7;
    static int tag(int t, int w);
    static int detag(int w);
    static int tagOf(int w);
    int addSym(string sym);
    string getSym(int w);
    void makeHeap();
    void makeHeap(int size);
    int getTop();
    int setTop(int top);
    void clear();
    void push(int i);
    void expand();
    void ensureSize(int more);
    static vector<vector<string>> emaybeExpand(vector<string> Ws);
    static vector<vector<string>> mapExpand(vector<vector<string>> Wss);
    static vector<int> toNums(vector<Clause> clauses);
    int encode(int t, string s);
    static bool isVAR(int x);
    void setRef(int w, int r);
    void unwindTrail(int savedTop);
    int deref(int x);
    bool unify(int base);
    bool unify_args(int w1, int w2);
    static int relocate(int b, int cell);
    void pushCells(int b, int from, int to, int base);
    void pushCells(int b, int from, int to, vector<int> cs);
    int pushHead(int b, Clause C);
    vector<int> pushBody(int b, int head, Clause C);
    void makeIndexArgs(Spine G, int goal);
    vector<int> getIndexables(int ref);
    int cell2index(int cell);
    bool match(vector<int> xs, Clause C0);
    Spine * unfold(Spine G);
    Spine * answer(int ttop);
    bool hasClauses(Spine S);
    bool hasGoals(Spine S);
    void popSpine();

};


#endif //CPROLOG_ENGINE1_H
