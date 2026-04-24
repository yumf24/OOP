#pragma once

#include "Value.h"
#include "Operator.h"

class Constant: public Value {
    int value;
public:
    Constant(int _value);
    int calc() override;
    void set_value(int new_value);
};

class Plus: public Operator {
    int value;
    long long int last_version = -1;
public:
    Plus(Value *r1, Value *r2);
    int calc() override;
};

class Multiply: public Operator {
    int value;
    long long int last_version = -1;
public:
    Multiply(Value *r1, Value *r2);
    int calc() override;
};

class Sub: public Operator {
    int value;
    long long int last_version = -1;
public:
    Sub(Value *r1, Value *r2);
    int calc() override;
};

class Print: public Value{
    Value *v1;
    int value;
    long long int last_version = -1;
public:
    Print(Value *r1);
    int calc() override;
};
