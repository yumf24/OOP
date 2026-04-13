#ifndef __A_H
#define __A_H

class A {
private:
    static int count;
public:
    void printRef();
    A() {count++;}
    ~A() {count--;}

};

#endif