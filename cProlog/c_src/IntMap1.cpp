//
// Created by Bidbip on 10/8/2017.
//

#include "IntMap.h"

using namespace std;

static int FREE_KEY = 0;
static int NO_VALUE = 0;
static int INT_PHI = 0x9E3779B9;
typedef vector<int> intVector;

IntMap::IntMap() {
    i_size = 4;
    m_fillFactor = .75f;
    init();
}

IntMap::IntMap(int size) {
    i_size = size;
    m_fillFactor = .75f;
    init();
}

IntMap::IntMap(int size, float fillFactor) {
    i_size = size;
    m_fillFactor = fillFactor;
    init();
}

void IntMap::init() {
    if (m_fillFactor <= 0 || m_fillFactor >= 1) {
        //errpr
    }
    if (i_size <= 0) {
        //error
    }
    int capacity = arraySize(i_size, m_fillFactor);

    m_mask = capacity -1;
    m_mask2 = capacity *2 -1;

    //m_data = new int[capacity*2];
    m_data.reserve(capacity*2);
    m_threshold = (int) (capacity * m_fillFactor);
}

int IntMap::get(int key) {
    int ptr = (phiMix(key) & m_mask) << 1;

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

bool IntMap::contains(int key) {
    return NO_VALUE != get(key);
}

bool IntMap::add(int key) {
    return NO_VALUE != put(key, 666);
}

bool IntMap::mDelete(int key) {
    return NO_VALUE != remove(key);
}

bool IntMap::isEmpty() {
    return 0 == m_size;
}

void IntMap::intersect0(IntMap &m, vector<IntMap> &maps, vector<IntMap> &vmaps, IntStack &r) {
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
                int vval = vmap.get(key);
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

IntStack IntMap::interect(vector<IntMap> &maps, vector<IntMap> &vmaps) {
    IntStack *r = new IntStack();
    intersect0(maps[0], maps, vmaps, *r);
    intersect0(vmaps[0], maps, vmaps, *r);
    return *r;
}

int IntMap::put(int key, int value) {
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

int IntMap::remove(int key) {
    if (key == FREE_KEY) {
        if (!m_hasFreeKey) {
            return NO_VALUE;
        }
        m_hasFreeKey = false;
        --m_size;
        return m_freeValue;
    }
    int ptr = (phiMix(key) & m_mask) << 1;
    int k = m_data[ptr];

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

int IntMap::size() {
    return m_size;
}

int IntMap::shiftKeys(int pos) {
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

void IntMap::rehash(int newCapacity) {
    m_threshold = (int) (newCapacity / 2 * m_fillFactor);
    m_mask = newCapacity / 2 - 1;
    m_mask2 = newCapacity - 1;

    int oldCapacity = m_data.size();
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

long IntMap::nextPowerOFTwo(long x) {
    if (x == 0) {
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
int IntMap::arraySize(int expected, float f) {
    long s = fmax(2, nextPowerOFTwo((long)ceil(expected / f)));
    if (s > 1 << 30) {
        cout << "error" << endl;
        return -1;
    }
    return (int) s;
}

int IntMap::phiMix(int x) {
    int h = x * INT_PHI;
    return h ^ h >> 16;
}
