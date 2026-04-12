#pragma once

class Shape {
public:
    virtual double getArea()=0;
    virtual ~Shape()=default;
};

class Rectangle: public Shape {
    double width, height;
public:
    Rectangle(double w, double h): width(w), height(h) {}
    double getArea() override;
    ~Rectangle()=default;
};

class Circle: public Shape {
    double radius;
public:
    static const double pi;
    Circle(double r): radius(r) {}
    double getArea() override;
    ~Circle()=default;
};
