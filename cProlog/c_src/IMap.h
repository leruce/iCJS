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

//template <class T>
class IMap {
public:
    IMap();
    void clear();
    bool put(int key, int val);
    IntMap get(int key);
    bool remove(int key, int val);
    bool remove(int key);
    int size();
    //Dont need keySet/keyIterator.
    static vector<IMap> create(int l);
    static bool put(vector<IMap> imaps, int pos, int key, int val );
    static vector<int> get(vector<IMap> imaps, vector<IntMap> vmaps, vector<int> keys);
    static string show(vector<IMap> imaps);
    static string show(vector<int> is);

private:
    unordered_map<int, IntMap> *Umap;
};


#endif //CPROLOG_IMAP_H
