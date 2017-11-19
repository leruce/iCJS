//
// Created by COLLEEN VANDERBILT on 10/1/17.
//

#ifndef IPROLOG_INTMAP_H
#define IPROLOG_INTMAP_H

#include "IntStack.h"
#include <vector>
#include <cmath>

using namespace std;
class IntMap {
public:
    IntMap();
    IntMap(int size);
    IntMap(int size, float fillFactor);
    void init();
    int get(int key);
    bool contains(int key);
    bool add(int key);
    bool mDelete(int key);
    bool isEmpty();
    static void intersect0(IntMap &m, vector<IntMap> &maps, vector<IntMap> &vmaps, IntStack &r);
    static IntStack interect(vector<IntMap> &maps, vector<IntMap> &vmaps);
    int put(int key, int value);
    int remove(int key);
    int size();
    //String toString();
private:
    std::vector<int> m_data;
    bool m_hasFreeKey =  false;
    int m_freeValue = 0;
    float m_fillFactor = 0;
    int m_threshold = 0;
    int m_size = 0;
    int i_size = 0;
    int m_mask = 0;
    int m_mask2 = 0;
    int shiftKeys(int pos);
    void rehash(int newCapacity);
    static long long nextPowerOFTwo(long long x);
    static int arraySize(int expected, float f);
    static int phiMix(int x);
};



#endif //IPROLOG_INTMAP_H
