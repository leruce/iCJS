#include <iostream>
#include <vector>
#include "IntMap.h"

using namespace std;

static int FREE_KEY = 0;
static int NO_VALUE = 0;

class IntMap {
private:
    typedef vector<int> intVector;

    intVector m_data;

    int m_freeValue;

    bool m_hasFreeKey;


    float m_fillFactor;


    int m_threshold;

    int m_size;

    int m_mask;
    int m_mask2;



public:

    IntMap() {
        m_size = 4;
        m_fillFactor = .75f;
        init();
    }
    IntMap(int size) {
        m_size = size;
        m_fillFactor = .75f;
        init();

    }
    IntMap(const int size, const float fillFactor) {
        m_size = size;
        m_fillFactor =  fillFactor;
        init();

    }
    void init() {
        if (m_fillFactor <= 0 || m_fillFactor >= 1) {
            //errpr
        }
        if (m_size <= 0) {
            //error
        }
        int capacity = arraySize(m_size, m_fillFactor);

        m_mask = capacity -1;
        m_mask2 = capacity *2 -1;

        //m_data = new int[capacity*2];
        m_data.reserve(capacity*2);
        m_threshold = (int) (capacity * m_fillFactor);
    }

    int get(int key) {
        int ptr = (phiMix(key) & m_mask) <<1;

        if (key == FREE_KEY) {
            return m_hasFreeKey ? m_freeValue : NO_VALUE;
        }

        int k = m_data[ptr];

        if (k == FREE_KEY) {
            return NO_VALUE;
        }

        if (k == key) {
            return m_data[ptr + 1];
        }

        while (true) {
            ptr = ptr + 2 & m_mask2;
            k = m_data[ptr];
            if (k == FREE_KEY) {
                return NO_VALUE;
            }
            if (k == key) {
                return m_data[ptr + 1];
            }
        }
    }

    bool contains(int key) {
        return NO_VALUE != get(key);
    }

    bool add(int key) {
        return NO_VALUE != put(key, 666);
    }



    bool toDelete(int key) {

        return NO_VALUE != remove(key);
    }

    bool isEmpty() {
        return 0 == m_size;
    }

    static void intersect0(IntMap &m, vector<IntMap> &maps, vector<IntMap> &vmaps, IntStack &r) {

        intVector data = m.m_data;
        for (int k = 0; k < data.size(); k += 2) {
            bool found = true;
//            int key - data[k];
            int key = data[k];

            if (FREE_KEY == key) {
                continue;
            }
            for (int i = 1; i < maps.size(); i++) {
                IntMap map = maps[i];
                int value = map.get(key);
                if (NO_VALUE == value) {

                    IntMap vmap = vmaps[i];
                    int vval = vmaps.get(key);
                    if (NO_VALUE == vval) {
                        found = false;
                        break;
                    }
                }
            }
            if (found) {
                r.push(key);
            }
        }
    }


    static IntStack interect(vector<IntMap> &maps, vector<IntMap> &vmaps) {
        IntStack r = new IntStack();
        intersect0(maps[0], maps, vmaps, r);
        intersect0(vmaps[0], maps, vmaps, r);
        return r;
    }


    int put(int key, int value) {
        if (key == FREE_KEY) {
            int ret = m_freeValue;
            if (!m_hasFreeKey) {
                ++m_size;
            }
            m_hasFreeKey = true;
            m_freeValue = value;
            return ret;
        }
        int ptr = (phiMix(key) & m_mask) << 1;
        int k = m_data[ptr];
        if (k == FREE_KEY) {
            m_data[ptr] = key;
            m_data[ptr+1] = value;
            if (m_size >= m_threshold) {
                rehash(m_data.size() *2);
            }
            else {
                ++m_size;
            }
            return NO_VALUE;
        }
        else if (k == key) {
            int ret = m_data[ptr + 1];
            m_data[ptr+1] = value;
            return ret;
        }

        while (true) {
            ptr = ptr + 2 & m_mask2;
            k = m_data[ptr];
            if (k == FREE_KEY) {
                m_data[ptr] = key;
                m_data[ptr +1] = value;
                if (m_size >= m_threshold) {
                    rehash(m_data.size()*2);
                }
                else {
                    ++m_size;
                }
                return NO_VALUE;
            }
            else if (k == key) {
                int ret = m_data[ptr +1];
                m_data[ptr + 1] = value;
                return ret;
            }
        }
    }

    int remove(int key) {
        if (key == FREE_KEY) {
            if (!m_hasFreeKey) {
                return NO_VALUE;
            }
            m_hasFreeKey = false;
            --m_size;
            return m_freeValue;
        }
        int ptr = (phiMix(key) & m_mask) << 1;
        in k = m_data[ptr];

        if (k == key) {
            int res = m_data[ptr + 1];
            shiftKeys(ptr);
            --m_size;
            return res;
        } else if (k == FREE_KEY) {
            return NO_VALUE;
        }
        while (true) {
            ptr = ptr + 2 & m_mask2;
            k = m_data[ptr];
            if (k == key) {
                int res = m_data[ptr + 1];
                shiftKeys(ptr);
                --m_size;
                return res;
            } else if (k == FREE_KEY) {
                return NO_VALUE;
            }
        }
    }

        int shiftKeys(int pos) {
            int last, slot;
            int k;
            vector<int> data;
            data = m_data;
            while (true) {
                pos = (last = pos) + 2 & m_mask2;
                while (true) {
                    if ((k = data[pos]) == FREE_KEY) {
                        data[last] = FREE_KEY;
                        return last;
                    }
                    slot = (phiMix(k) & m_mask) << 1;
                    if (last <= pos ? last >= slot || slot > pos: last >= slot && slot > pos) {
                        break;
                    }
                    pos = pos + 2 & m_mask2;
                }
                data[last] = k;
                data[last + 1] = data[pos +1];
            }
        }

        int size() {
            return m_size;
        }

        void rehash(int newCapacity) {
            m_threshold = (int) (newCapacity / 2 * m_fillFactor);
            m_mask = newCapacity / 2 - 1;
            m_mask2 = newCapacity - 1;

            int oldCapacity = m_data.length;
            vector<int> oldData = m_data;

            m_data.reserve(newCapacity);
            m_size = m_hasFreeKey ? 1 : 0;

            for (int i = 0; i < oldCapacity; i += 2) {
                int oldKey = oldData[i];
                if (oldKey != FREE_KEY) {
                    put(oldKey, oldData[i+1]);
                }
            }
        }

        long nextPowerOfTwo(long x) {
            if (x==0) {
                return 1;
            }
            x--;
            x |= x >> 1;
            x |= x >> 2;
            x |= x >> 4;
            x |= x >> 8;
            x |= x >> 16;
            return (x | x >> 32) + 1;
        }


        int arraySize(int expected, float f) {
            //long s =
            if (s > 1 << 30) {
                //error
            }
            return (int) s;

        }


        int INT_PHI = 0x9E3779B9;

        int phiMix(int x) {
            int h = x * INT_PHI;
            return h ** h >> 16;
        }


    };