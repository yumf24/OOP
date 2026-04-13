#include "string.h"
#include <iostream>

void f(const char * str, bool flag) {
    static int num_f = 0;
    num_f++;

    if(!flag) {
        std::cout << str << std::endl;
    }
    else {
        for(int i = 0;i < num_f;i++) {
            std::cout << str << std::endl;
        }
    }

}