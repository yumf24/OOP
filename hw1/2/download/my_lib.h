#ifndef MY_LIB_H
#define MY_LIB_H

#include <iostream>

void print();

void print(int x);

void print(bool x);

void print(std::string s);
void print(const char *s);

void print(char c);

std::string input();

class Array {
    int size{};
    int a[100]{};
public:
    void append(int x);

    void pop();

    int getSize();
    int *getArray();
};

void print(Array a);

#endif
