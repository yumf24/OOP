#include "A.h"
#include <iostream>

int A::count = 0;

void A::printRef() {
    std::cout << count << std::endl;
}