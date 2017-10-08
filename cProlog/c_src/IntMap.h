//
// Created by COLLEEN VANDERBILT on 10/1/17.
//

#ifndef IPROLOG_INTMAP_H
#define IPROLOG_INTMAP_H

#include "IntStack.h"
#include <vector>
#include <math.h>

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
    bool m_hasFreeKey;
    int m_freeValue;
    float m_fillFactor;
    int m_threshold;
    int m_size;
    int i_size;
    int m_mask;
    int m_mask2;
    int shiftKeys(int pos);
    void rehash(int newCapacity);
    static long nextPowerOFTwo(long x);
    static int arraySize(int expected, float f);
    static int phiMix(int x);
};



#endif //IPROLOG_INTMAP_H
