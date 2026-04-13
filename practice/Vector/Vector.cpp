#include "Vector.h"
#include <iostream>

using std::cout, std::cin, std::endl;

Vector Vector::operator+(const Vector &b) {
    return (Vector(x+b.x, y+b.y, z+b.z));
}

Vector Vector::operator-(const Vector &b) {
    return (Vector(x-b.x, y-b.y, z-b.z));
}

Vector Vector::operator+(const double b) {
    return (Vector(x+b, y+b, z+b));
}

Vector Vector::operator-(const double b) {
    return (Vector(x-b, y-b, z-b));
}

Vector Vector::operator*(const double b) {
    return (Vector(x*b, y*b, z*b));
}

Vector operator+(const double b,const Vector &vec) {
    return (Vector(vec.x+b, vec.y+b, vec.z+b));
}

Vector operator-(const double b,const Vector &vec) {
    return (Vector(b-vec.x, b-vec.y, b-vec.z));
}

Vector operator*(const double b,const Vector &vec) {
    return (Vector(vec.x*b, vec.y*b, vec.z*b));
}

std::istream& operator>>(std::istream &in,Vector &vec) {
    double x,y,z;
    in >> vec.x >> vec.y >> vec.z;
    return in;
}

std::ostream& operator<<(std::ostream &out,const Vector &vec) {
    out << "x = "<< vec.x << endl;
    out << "y = "<< vec.y << endl;
    out << "z = "<< vec.z << endl;
    return out;
}