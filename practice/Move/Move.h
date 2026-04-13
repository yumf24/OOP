#ifndef __MOVE_H
#define __MOVE_H

class Move {
private:
    double x;
    double y;
    double calc();
public:
    Move(double a = 0, double b = 0);
    void display();
    double get_x();
    double get_y();
    void reset(double a = 0, double b = 0);
};

#endif