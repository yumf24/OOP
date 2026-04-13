#include "Move.h"
#include <iostream>

double Move::calc() {
    return (x*y);
}

Move::Move(double a, double b) {
    x = a;
    y = b;
}

void Move::display() {
    std::cout << "The result of calc is " << this->calc() << std::endl;
}

double Move::get_x() {
    return x;
}

double Move::get_y() {
    return y;
}

void Move::reset(double a, double b) {
    x = a;
    y = b;
}