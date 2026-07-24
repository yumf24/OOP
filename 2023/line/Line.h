#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Line {
    T k,b;
public:
    Line(T _k, T _b = 0): k(_k), b(_b) {}
    const T get_k() const {return k;}
    const T get_b() const {return b;}
    void show() {
        cout << k << "," << b << endl;
    }
    bool intersect(const Line& r) {
        if(abs(k-r.get_k()) < 1e-6) {
            if(abs(b-r.get_b()) < 1e-6) {
                return true;
            }
            return false;
        }
        return true; 
    }
    bool operator<(const Line& rhs) {
        if(k < rhs.get_k()) return true;
        return false;
    }
};