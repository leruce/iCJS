//
// Created by Bidbip on 12/2/2017.
//

#include "Engine1.h"
#include "Prog.h"
#include "main.h"

using namespace std;

Engine1::Engine1(string fname) {
    syms = new map<string, int>;
    slist = new vector<string>;
    makeHeap();
    trail = new IntStack;
    ustack = new IntStack;
    clauses = dload(fname);
    cls = toNums(clauses);
    query = init();
    vmaps = vcreate(MAXIND);
    imaps = index(clauses, vmaps);
}

int Engine1::tag(int t, int w) {
    return -((w << 3) + t);
}

int Engine1::detag(int w) {
    return (-w >> 3);
}

int Engine1::tagOf(int w) {
    return (-w & 7);
}

int Engine1::addSym(string sym) {
    std::map<string, int>::iterator it;
    it = syms->find(sym);
    if (it == syms->end()) {
        int i = syms->size();
        syms->emplace(sym, i);
        slist->push_back(sym);
    }
    return it->second;
}

string Engine1::getSym(int w) {
    if (w < 0 || w >= slist->size()) {
        return ("BADSYMREF = " + to_string(w));
    }
    return (*slist)[w];
}

void Engine1::makeHeap(int size) {
    heap = vector<int>(size);
    clear();
}

void Engine1::makeHeap() {
    makeHeap(MINSIZE);
}

int Engine1::getTop() {
    return top;
}
int Engine1::setTop(int top) {
    this->top = top;
}

void Engine1::clear() {
    top = -1;
}

void Engine1::push(int i) {
    heap[++top] = i;
}
int Engine1::size() {
    return top + 1;
}

//Come back and make sure this works
void Engine1::expand() {
    int l = heap.size();
    vector<int> newstack(l << 1);
    newstack.insert(newstack.end(), heap.begin(), heap.end());
    heap = newstack;
}

void Engine1::ensureSize(int more) {
    if (1 + top + more >= heap.size()) {
        expand();
    }
}

vector<vector<string>> Engine1::emaybeExpand(vector<string> Ws) {
    string w = Ws[0];
    if (w.length() < 2 || "l:" != w.substr(0,2)) {
        return {};
    }
    int l = Ws.size();
    vector<vector<string>> Rss;
    string V = w.substr(2);
    for (int i = 1; i < l; i++) {
        vector<string> Rs(4);
        string Vi = 1 == i ? V : V + "__" + to_string(i - 1);
        string Vii = V + "__" + to_string(i);
        Rs[0] = "h:" + Vi;
        Rs[1] = "c:list";
        Rs[2] = Ws[i];
        Rs[3] = i == l - 1 ? "c:nil" : "v:" + Vii;
        Rss.push_back(Rs);
    }
    return Rss;
}

vector<vector<string>> Engine1::mapExpand(vector<vector<string>> Wss) {
    vector<vector<string>> Rss;
    for (auto Ws : Wss) {
        vector<vector<string>> Hss = emaybeExpand(Ws);
        if (Hss.empty()) {
            vector<string> ws(Ws.size());
            for (int i = 0; i < ws.size(); i++) {
                ws[i] = Ws[i];
            }
            Rss.push_back(ws);
        }
        else {
            for (auto X : Hss) {
                Rss.push_back(X);
            }
        }
    }
    return Rss;
}

vector<Clause *> Engine1::dload(string s) {
    bool fromFile = true;
    vector<vector<vector<string>>> Wsss = iProlog::Toks::toSentences(s, fromFile);
    vector<Clause *> Cs;
    for (auto Wss : Wsss) {
        map<string, IntStack> refs;
        IntStack *cs = new IntStack;
        IntStack *gs = new IntStack;

        vector<vector<string>> Rss = mapExpand(Wss);
        int k = 0;
        for (auto ws : Rss) {
            int l = ws.size();
            gs->push(tag(R, k++));
            cs->push(tag(A, l));
            for (auto w: ws) {
                if (1 == w.size()) {
                    w = "c:" + w;
                }
                string L =  w.substr(2);
                switch (w[0]) {
                    case 'c':
                        cs->push(encode(C, L));
                        k++;
                        break;
                    case 'n':
                        cs->push(encode(N, L));
                        k++;
                        break;
                    case 'v': {
                        map<string, IntStack>::iterator it;
                        it = refs.find(L);
                        IntStack Is;
                        if (it == refs.end()) {
                            refs[L] = Is;
                        } else {
                            Is = it->second;
                        }
                        Is.push(k);
                        cs->push(tag(BAD, k));
                        k++;
                    }
                        break;
                    case 'h': {
                        map<string, IntStack>::iterator it;
                        it = refs.find(L);
                        IntStack Is;
                        if (it == refs.end()) {
                            refs[L] = Is;
                        } else {
                            Is = it->second;
                        }
                        Is.push(k-1);
                        cs->set(k-1, tag(A, l-1));
                        gs->pop();
                        }
                        break;
                    default:
                    Main::pp("FORGOTTEN=" + w);
                }
            }
        }
        auto K = refs.begin();

        while(K != refs.end()) {
            IntStack Is = K->second;
            int leader = -1;
            for (auto j : Is.toVec()) {
                if (A == tagOf(cs->get(j))) {
                    leader = j;
                    break;
                }
            }
            if (-1 == leader) {
                leader = Is.get(0);
                for (auto i : Is.toVec()) {
                    if (i == leader) {
                        continue;
                    }
                    cs->set(i, tag(R, leader));
                }
            }

            K++;
        }
        int neck = 1 == gs->size() ? cs->size() : detag(gs->get(1));
        vector<int> tgs = gs->toVec();

        Clause * C = putClause(cs->toVec(), tgs, neck);
        Cs.push_back(C);
    }
    int ccount = Cs.size();
    vector<Clause *> cls(ccount);
    for (int i = 0; i < ccount; i++) {
        cls[i] = Cs[i];
    }
    return cls;
}

vector<int> Engine1::toNums(vector<Clause *> clauses) {
    int l = clauses.size();
    vector<int> cls(l);
    for (int i = 0; i < l; i++) {
        cls[i] = i;
    }
    return cls;
}

int Engine1::encode(int t, string s) {
    int w;
    try {
        w = boost::lexical_cast<int>(s);
    } catch (boost::bad_lexical_cast const&) {
        if (C == t) {
            w = addSym(s);
        }
        else {
            return tag(BAD, 666);
        }
    }
    return tag(t,w);
}

bool Engine1::isVAR(int x) {
    return tagOf(x) < 2;
}

int Engine1::getRef(int x) {
    return heap[detag(x)];
}

void Engine1::setRef(int w, int r) {
    heap[detag(w)] = r;
}

void Engine1::unwindTrail(int savedTop) {
    while (savedTop < trail->getTop()) {
        int href = trail->pop();
        setRef(href, href);
    }
}

int Engine1::deref(int x) {
    while (isVAR(x)) {
        int r = getRef(x);
        if (r == x) {
            break;
        }
        x = r;
    }
    return x;
}

string Engine1::showTerm(int x) {
    return showTerm(exportTerm(x));
}

string Engine1::showTerm(ObjectE * O) {
    //do the static-vistor thing here.
}
ObjectE * Engine1::exportTerm(int x) {
    x = deref(x);
    int t = tagOf(x);
    int w = detag(x);
    //instead of using ObjectE * we use auto
    //auto res = new ObjectE;
    ObjectE res;
    switch(t) {
        case C:
            res = getSym(w);
            break;
        case N:
            res = w;
            break;
        case V:
            res = "V" + std::to_string(w);
            break;
        case R:  {
            int a = heap[w];
            if (A != tagOf(a)) {
                res = "*** should be A, found=" + showCell(a);
                return &res;
            }
            int n = detag(a);
            vector< ObjectE * > arr(n);
            int k = w + 1;
            for (int i = 0; i < n; i++) {
                int j = k + i;
                arr[i] = exportTerm(heap[j]);
            }
            res = arr;
        }
            break;
        default:
            res = "*BAD TERM*" + showCell(x);
    }
    ObjectE *Tres = new ObjectE;
    Tres = &res;
    return Tres;
}

void Engine1::ppTrail() {
    for (int i = 0; i <= trail->getTop(); i++) {
        int t = trail->get(i);
        Main::pp("trail[" + to_string(i) + "]=" + showCell(t) + ":" + showTerm(t)); //May need to rewrite into one string.
    }
}

vector<int> Engine1::getSpine(vector<int> cs) {
    int a = cs[1];
    int w = detag(a);
    vector<int> rs;
    rs.resize(w - 1);
    for (int i = 0; i < w-1; i++) {
        int x = cs[3+i];
        int t = tagOf(x);
        if (R != t) {
            Main::pp("*** getSpine: unexpected tag=" + to_string(t));
            return {}; //FIX NULLS
        }
        rs[i] = detag(x);
    }
    return rs;
}

string Engine1::showCell(int w) {
    int t = tagOf(w);
    int val = detag(w);
    string s;
    switch (t) {
        case V:
            s = "v:" + to_string(val);
            break;
        case U:
            s = "u:" + to_string(val);
            break;
        case N:
            s = "n:" + to_string(val);
            break;
        case C:
            s = "c:" + getSym(val);
            break;
        case R:
            s = "r:" + to_string(val);
            break;
        case A:
            s = "a:" + to_string(val);
            break;
        default:
            s = "*BAD*=" + to_string(val);
    }
    return s;
}

string Engine1::showCells(int base, int len) {
    string buf;
    for (int k = 0; k <len; k++) {
        int instr = heap[base + k];
        buf += "[";
        buf += to_string(base + k);
        buf += "]";
        buf += showCell(instr);
        buf += " ";
    }
    return buf;
}

string Engine1::showCells(vector<int> cs) {
    string buf;
    for (int k = 0; k < cs.size(); k++) {
        buf += "[";
        buf += showCell(cs[k]);
        buf += " ";
    }
    return buf;
}

bool Engine1::unify(int base) {
    while (!ustack->isEmpty()) {
        int x1 = deref(ustack->pop());
        int x2 = deref(ustack->pop());
        if (x1 != x2) {
            int t1 = tagOf(x1);
            int t2 = tagOf(x2);
            int w1 = detag(x1);
            int w2 = detag(x2);
            if (isVAR(x1)) {
                if (isVAR(x2) && w2 > w1) {
                    heap[w2] = x1;
                    if (w2 <= base) {
                        trail->push(x2);
                    }
                }
                else {
                    heap[w1] = x2;
                    if (w1 <= base) {
                        trail->push(x1);
                    }
                }
            }
            else if (isVAR(x2)) {
                heap[w2] = x1;
                if (w2 <= base) {
                    trail->push(x2);
                }
            }
            else if (R == t1 && R == t2) {
                if (!unify_args(w1, w2))
                    return false;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool Engine1::unify_args(int w1, int w2) {
    int v1 = heap[w1];
    int v2 = heap[w2];
    int n1 = detag(v1);
    int n2 = detag(v2);

    if (n1 != n2) {
        return false;
    }
    int b1 = 1 + w1;
    int b2 = 1 + w2;
    for (int i = n1 - 1; i >= 0; i--) {
        int i1 = b1 + i;
        int i2 = b2 + i;
        int u1 = heap[i1];
        int u2 = heap[i2];
        if (u1 == u2) {
            continue;
        }
        ustack->push(u2);
        ustack->push(u1);
    }
    return true;
}

Clause * Engine1::putClause(vector<int> cs, vector<int> gs, int neck) {
    int base = size();
    int b = tag(V, base);
    int len = cs.size();
    pushCells(b, 0, len, cs);
    for (int i = 0; i < gs.size(); i++) {
        gs[i] = relocate(b, gs[i]);
    }
    vector<int> xs = getIndexables(gs[0]);
    return new Clause(len, gs, base, neck, xs);
}

int Engine1::relocate(int b, int cell) {
    return tagOf(cell) < 3 ? cell + b : cell;
}

void Engine1::pushCells(int b, int from, int to, int base) {
    ensureSize(to - from);
    for (int i = from; i < to; i++) {
        push(relocate(b, heap[base+i]));
    }
}

void Engine1::pushCells(int b, int from, int to, vector<int> cs) {
    ensureSize(to -  from);
    for (int i = from; i < to; i++) {
        push(relocate(b, cs[i]));
    }
}

int Engine1::pushHead(int b, Clause * C) {
    pushCells(b, 0,C->neck, C->base );
    int head = C->hgs[0];
    return relocate(b, head);
}

vector<int> Engine1::pushBody(int b, int head, Clause * C) {
    pushCells(b, C->neck, C->len, C->base);
    int l = C->hgs.size();
    vector<int> gs(l);
    gs[0] = head;
    for (int k = 1; k < l; k++) {
        int cell = C->hgs[k];
        gs[k] = relocate(b, cell);
    }
    return gs;
}

void Engine1::makeIndexArgs(Spine G, int goal) {
    if (!G.xs.empty()) {
        return;
    }
    int p = 1 + detag(goal);
    int n = min(MAXIND, detag(getRef(goal)));
    vector<int> xs(MAXIND);
    for (int i = 0; i < n; i++) {
        int cell = deref(heap[p + i]);
        xs[i] = cell2index(cell);
    }
    G.xs = xs;
    //CHECK FOR THE IMAPS NULL STUFF
    if (imaps.empty()) {
        return;
    }
    vector<int> cs = IMap::get(imaps, vmaps, xs);
    G.cs = cs;
}

vector<int> Engine1::getIndexables(int ref) {
    int p = 1 + detag(ref);
    int n = detag(getRef(ref));
    vector<int> xs(MAXIND);
    for (int i = 0; i < MAXIND; i++) {
        int cell = deref(heap[p + i]);
        xs[i] = cell2index(cell);
    }
    return xs;
}


int Engine1::cell2index(int cell) {
    int x = 0;
    int t = tagOf(cell);
    switch(t) {
        case R:
            x = getRef(cell);
            break;
        case C:
        case N:
            x = cell;
            break;
        default:
            break;
    }
    return x;
}

bool Engine1::match(vector<int> xs, Clause * C0) {
    for (int i = 0; i < MAXIND; i++) {
        int x = xs[i];
        int y = C0->xs[i];
        if (0 == x || 0 == y) {
            continue;
        }
        if (x != y){
            return false;
        }
    }
    return true;
}

Spine * Engine1::unfold(Spine G) {
    int ttop = trail->getTop();
    int htop = getTop();
    int base = htop + 1;
    int goal = IntList::getHead(G.gs);
    makeIndexArgs(G, goal);
    int last = G.cs.size();
    for (int k = G.k; k < last; k++) {
        Clause * C0 = clauses[G.cs[k]];
        if (!match(G.xs, C0)) {
            continue;
        }
        int base0 = base - C0->base;
        int b = tag(V, base0);
        int head = pushHead(b, C0);
        ustack->clear();
        ustack->push(head);
        ustack->push(goal);
        if (!unify(base)) {
            unwindTrail(ttop);
            setTop(htop);
            continue;
        }
        vector<int> gs = pushBody(b, head, C0);
        IntList *newgs = IntList::getTail(IntList::app(gs, IntList::getTail(G.gs)));
        G.k = k + 1;
        if (!IntList::isEmpty(newgs)) {
            return new Spine(gs, base, IntList::getTail(G.gs), ttop, 0, cls);
        }
        else {
            return answer(ttop);
        }
    }
    return nullptr;
}

Clause * Engine1::getQuery() {
    return clauses[clauses.size()-1];
}

Spine * Engine1::init() {
    int base = size();
    Clause *G = getQuery();
    Spine *Q = new Spine(G->hgs, base, IntList::empty, trail->getTop(), 0, cls);
    spines.push_back(*Q);
    return Q;
}

Spine * Engine1::answer(int ttop) {
    return new Spine(spines[0].hd, ttop);
}

bool Engine1::hasClauses(Spine S) {
    return S.k < S.cs.size();
}

bool Engine1::hasGoals(Spine S) {
    return !IntList::isEmpty(S.gs);
}

void Engine1::popSpine() {
    Spine G = spines.back();
    spines.pop_back();
    unwindTrail(G.ttop);
    setTop(G.base - 1);
}

Spine * Engine1::yield() {
    while (!spines.empty()) {
        Spine G = spines.back();
        if (!hasClauses(G)) {
            popSpine();
            continue;
        }
        Spine *C = unfold(G);
        if (C == nullptr) {
            popSpine();
            continue;
        }
        if (hasGoals(*C)) {
            spines.push_back(*C);
            continue;
        }
        return C;
    }
    return nullptr;
}

ObjectE * Engine1::ask() {
    query = yield();
    if (nullptr == query) {
        return nullptr;
    }
    int res = answer(query->ttop)->hd;
    ObjectE *R = exportTerm(res);
    unwindTrail(query->ttop);
    return R;
}

void Engine1::run() {
    long ctr = 0L;
    for (; ; ctr++) {
        ObjectE *A = ask();
        if (nullptr == A) {
            break;
        }
        if (ctr < 5) {
            Prog::println("[" + to_string(ctr) + "] " + "***ANSWER=" + showTerm(A));
        }
    }
    if (ctr > 5) {
        Prog::println("...");
    }
    Prog::println("TOTAL ANSWER=" + to_string(ctr));
}

vector<IntMap> Engine1::vcreate(int l) {

}

void Engine1::put(vector<IMap> imaps, vector<IntMap> vss, vector<int> keys, int val) {
    for (int i = 0; i < imaps.size(); i++) {
        int key = keys[i];
        if (key != 0) {
            IMap::put(imaps, i, key, val);
        }
        else {
            vss[i].add(val);
        }
    }
}

vector<IMap> Engine1::index(vector<Clause *> clauses, vector<IntMap> vmaps) {
    if (clauses.size() < START_INDEX) {
        return {};
    }
    vector<IMap> imaps = IMap::create(vmaps.size());
    for (int i =0; i < clauses.size(); i++) {
        Clause *c = clauses[i];
        put(imaps, vmaps, c->xs, i+1);
    }
    Main::pp("Index");
    Main::pp(IMap::show(imaps));
    //Main::pp(vmaps.toString())
    Main::pp("");
    return imaps;
}