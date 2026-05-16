#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
    Point (Pos p): pos(p) {}
    bool operator<(const Point &right) const {
        return (pos < right.pos);
    }
};

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    bool has_sorted;
    
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
        has_sorted = false;
    }

    A* find(Pos p) {
        if(!has_sorted) {
            std::sort(base.begin(), base.end());
            has_sorted = true;
        }

        /*
        for(auto t = base.begin(); t != base.end(); ++t) {
            if(p == t->pos) return &(t->value);
        }
        */

        // find value
        Point<A> need_to_find(p);
        auto it = std::lower_bound(base.begin(), base.end(), need_to_find);
        if(it != base.end() && it->pos == p) {
            return &(it->value);
        }

        return NULL;
    }
};

template <class A>
class Container<A, map<Pos, A> > : public BasicContainer<A> {
    map<Pos, A> base;
    
public:
    void insert(const Pos &p, const A &v) {
        base[p] = v;
    }

    A* find(Pos p) {
        // find value
        auto it = base.lower_bound(p);
        if(it != base.end() && it->first == p) {
            return &(it->second);
        }

        return NULL;
    }
};
#endif
