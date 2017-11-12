//
// Created by Bidbip on 11/8/2017.
//

#include "IMap.h"

//template class IMap<int>;
template <typename T>
IMap<T>::IMap() {
    Umap = new unordered_map<T, IntMap>;
}


template <typename T>
void IMap<T>::clear() {
    Umap->clear();
}

template <typename T>
bool IMap<T>::put(T key, int val) {
    typename unordered_map<T, IntMap>::const_iterator vals = Umap->find(key);
    IntMap *mVal;
    if (vals == Umap->end() ) {
       mVal = new IntMap();
        Umap->insert(key, mVal);
    }
    else {
        mVal = &vals->second;
    }
    return mVal->add(val);
}

template <typename T>
IntMap IMap<T>::get(T key) {
    IntMap *mVal;
    typename unordered_map<T, IntMap>::const_iterator vals = Umap->find(key);
    if (vals == Umap->end()) {
        mVal = new IntMap();
    }
    else {
        mVal = &vals->second;
    }
    return *mVal;
}

template <typename T>
bool IMap<T>::remove(T key, int val) {
    IntMap *mVal;
    typename unordered_map<T, IntMap>::const_iterator vals = Umap->find(key);
    mVal = &vals->second;
    bool ok = mVal->mDelete(val);
    if (mVal->isEmpty()) {
        Umap->erase(key);
    }
    return ok;
}

template <typename T>
bool IMap<T>::remove(T key) {
    return (0 != Umap->erase(key));
}

template <typename T>
int IMap<T>::size() {
    int cSize = 0;
    for (auto it : *Umap) {
        T key = it.first;
        IntMap vals = get(key);
        cSize += vals.size();
    }
    return cSize;
}

template <typename T>
vector<IMap<int>> IMap<T>::create(int l) {
    //goal is to create a vector of  IMaps
    IMap<int> *first = new IMap<int>;
    vector<IMap<int>> imaps;
    imaps.resize(l);
    return imaps;
}

template <typename T>
bool IMap<T>::put(vector<IMap<int>> imaps, int pos, int key, int val) {
    return imaps[pos].put(key, val);
}

template <typename T>
vector<int> IMap<T>::get(vector<IMap<int>> imaps, vector<IntMap> vmaps, vector<int> keys) {

}

template <typename T>
string IMap<T>::show(vector<IMap<int>> imaps) {

}

template <typename T>
string IMap<T>::show(vector<int> is) {

}