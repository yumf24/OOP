#include <iostream>
#include "A.h"

void f() {
    A obj;
    obj.printRef();
}

int main() {
    A *p = new A;
    p->printRef();
    f();
    delete p;
    return 0;
}
