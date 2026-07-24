#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include "Line.h"

using namespace std;

template<class T>
class Point {
    T x,y;
public:
    Point(T _x, T _y): x(_x), y(_y) {}
    void move(T dx, T dy) {
        x += dx;
        y += dy;
    }
    void show() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    bool check(const Line<T>& l) {
        T line_y = l.get_k()*x + l.get_b();
        if(abs(line_y - y) < 1e-6) {
            return true;
        }
        return false;
    }
};