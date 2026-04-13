#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>

class  Vector
{
private:
    double x, y, z;
public:
    Vector(double x=1, double y = 1, double z = 1) : x(x), y(y), z(z) {}
    ~ Vector() {}

    Vector operator+(const Vector &b);
    Vector operator-(const Vector &b);

    // Vector +-* num
    Vector operator+(const double b);
    Vector operator-(const double b);
    Vector operator*(const double b);

    // num +-* Vector 
    friend Vector operator+(const double b, const Vector &vec);
    friend Vector operator-(const double b, const Vector &vec);
    friend Vector operator*(const double b, const Vector &vec);

    // cout cin
    friend std::istream& operator>>(std::istream &in, Vector &vec);
    friend std::ostream& operator<<(std::ostream &out, const Vector &vec);
};

#endif