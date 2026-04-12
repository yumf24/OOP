#include "Map.h"
#include "Pair.h"

Map::Map(int n) {
    this->sz = 0;
    data = new Pair[n];
}

Map::~Map() {
    delete [] data;
}

int & Map::operator [](const string & k) {
    // 遍历所有Pair
    for(int i = 0;i < sz;i++) {
        if(data[i].hasKey(k)) {
            return data[i].getVal();
        }
    }
    data[sz] = Pair();
    data[sz].reset(k, 0);
    sz++;
    return data[sz-1].getVal();
}

int Map::operator [](const string & k) const {
    // 遍历所有Pair
    for(int i = 0;i < sz;i++) {
        if(data[i].hasKey(k)) {
            return data[i].getVal();
        }
    }
    return 0;
}

int Map::size() const {
    return sz;
}