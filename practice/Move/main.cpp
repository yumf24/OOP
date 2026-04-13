#include "Move.h"
#include <iostream>

int main() {
    Move m1(100, 100), m2;

    std::cout << "m1" << std::endl;
    m1.display();
    std::cout << "m1.x = " << m1.get_x() << std::endl;
    std::cout << "m1.y = " << m1.get_y() << std::endl;
    m1.reset();
    std::cout << "Reset m1" << std::endl;
    m1.display();
    std::cout << "m1.x = " << m1.get_x() << std::endl;
    std::cout << "m1.y = " << m1.get_y() << std::endl;


    std::cout << "m2" << std::endl;
    m2.display();
    std::cout << "m2.x = " << m2.get_x() << std::endl;
    std::cout << "m2.y = " << m2.get_y() << std::endl;

    return 0;
}