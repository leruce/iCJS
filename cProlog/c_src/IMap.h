//
// Created by Bidbip on 11/8/2017.
//

#ifndef CPROLOG_IMAP_H
#define CPROLOG_IMAP_H

#include <vector>
#include "IntMap.h"
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class IMap {
public:
    IMap();
    void clear();
    bool put(T key, int val);
    IntMap get(T key);
    bool remove(T key, int val);
    bool remove(T key);
    int size();
    //Dont need keySet/keyIterator.
    static vector<IMap<int>> create(int l);
    static bool put(vector<IMap<int> > imaps, int pos, int key, int val );
    static vector<int> get(vector<IMap<int> > imaps, vector<IntMap> vmaps, vector<int> keys);
    static string show(vector<IMap<int> > imaps);
    static string show(vector<int> is);

private:
    unordered_map<T, IntMap> *Umap;
};


#endif //CPROLOG_IMAP_H
