//
// Created by Bidbip on 11/8/2017.
//

#include "IMap.h"


//template <class T>
IMap::IMap() {
}


//template <class T>
void IMap::clear() {
    Umap.clear();
}

//template <class T>
bool IMap::put(int key, int val) {
    IntMap *mVal = Umap[key];
    if (mVal == nullptr) {
        mVal = new IntMap;
        Umap[key] = mVal;
    }
    return mVal->add(val);
}

//template <class T>
IntMap IMap::get(int key) {
    IntMap *mVal = Umap[key];
    if (mVal == nullptr) {
        mVal = new IntMap;
        Umap[key] = mVal;
    }
    return *mVal;
}

//template <class T>
bool IMap::remove(int key, int val) {
    IntMap *mVal = Umap[key];
    if (mVal == nullptr) {
        mVal = new IntMap;
        Umap[key] = mVal;
    }
    bool ok = mVal->mDelete(val);
    if (mVal->isEmpty()) {
        Umap.erase(key);
    }
    return ok;
}

//template <class T>
bool IMap::remove(int key) {
    return (0 != Umap.erase(key));
}

//template <class T>
int IMap::size() {
    int cSize = 0;
    for (auto it : Umap) {
        int key = it.first;
        IntMap vals = get(key);
        cSize += vals.size();
    }
    return cSize;
}

//template <class T>
vector<IMap> IMap::create(int l) {
    //goal is to create a vector of  IMaps
    IMap *first = new IMap;
    vector<IMap> imaps;
    imaps.resize(l);
    return imaps;
}

//template <class T>
bool IMap::put(vector<IMap> &imaps, int pos, int key, int val) {
    return imaps[pos].put(key, val);
}

//template <class T>
vector<int> IMap::get(vector<IMap> &imaps, vector<IntMap> &vmaps, vector<int> &keys) {

}


string IMap::show(vector<IMap> &imaps) {

}

//template <class T>
string IMap::show(vector<int> &is) {

}
