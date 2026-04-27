#pragma once
#include <string.h>

class Animal {
public:
    std::string name;
    Animal(std::string _name): name(_name) {}
    void action() {
        speak();
        swim();
    }
    virtual void speak() = 0;
    virtual void swim() = 0;
    virtual ~Animal() {}
};