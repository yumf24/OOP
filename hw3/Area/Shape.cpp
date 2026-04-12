#include "Shape.h"

double Rectangle::getArea() {
    return width*height;
}


const double Circle::pi = 3.14;

double Circle::getArea() {
    return pi*radius*radius;
}
