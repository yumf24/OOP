#pragma once

#include <iostream>
using namespace  std;


class Vehicle {
    size_t max_wheel_num, max_wing_num;
    size_t wheel, wing;
public:
    Vehicle(): wheel(0), wing(0), max_wheel_num(0), max_wing_num(0) {}
    void set_max_wheel_num(size_t n) {
        max_wheel_num = n;
    }

    void set_max_wing_num(size_t n) {
        max_wing_num = n;
    }

    bool finished() {
        if(wheel >= max_wheel_num && wing >= max_wing_num) {
            return true;
        } else {
            return false;
        }
    }
    void add_wheel() {
        wheel++;
    }
    void add_wing() {
        wing++;
    }
    void run() {
        if(wing > 0) {
            cout << "I am running and flying" << endl;
        }
        else {
            cout << "I am running" << endl;
        }
    }

};