#include "my_lib.h"

void print() {
    std::cout << std::endl;
}

void print(int x) {
    std::cout << x << std::endl;
}

void print(bool x) {
    std::cout << (x ? "True" : "False") << std::endl;
}

void print(std::string s) {
    std::cout << s << std::endl;
}

void print(const char *s) {
    std::cout << s << std::endl;
}

void print(char c) {
    std::cout << c << std::endl;
}

std::string input() {
    std::string s;
    std::cin >> s;
    return s;
}

// Array

void Array::append(int x) { a[size++] = x; }

void Array::pop() { size--; }

int Array::getSize() { return size; }

int * Array::getArray() {return a;}

void print(Array a) {
    int *array = a.getArray();
    for (int i = 0; i < a.getSize(); i++)
        std::cout << array[i] << (i == a.getSize() - 1 ? '\n' : ' ');
}
