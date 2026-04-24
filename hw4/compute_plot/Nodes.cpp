#include "Nodes.h"

long long int global_version = 0;

Constant::Constant(int _value): value(_value) {}
Plus::Plus(Value *r1, Value *r2): Operator(r1,r2) {
}
Multiply::Multiply(Value *r1, Value *r2):Operator(r1, r2) {}
Sub::Sub(Value *r1, Value *r2):Operator(r1, r2) {}
Print::Print(Value *r1): v1(r1) {}

int Constant::calc() {
    return value;
}

int Plus::calc() {
    if(global_version == last_version) return value;
    value = getV1() + getV2();
    last_version = global_version;
    return value;
}

int Multiply::calc() {
    if(global_version == last_version) return value;
    value = getV1() * getV2();
    last_version = global_version;
    return value;
}

int Sub::calc() {
    if(global_version == last_version) return value;
    value = getV1() - getV2();
    last_version = global_version;
    return value;
}

int Print::calc() {
    if(global_version == last_version) return value;
    value = v1->calc();
    last_version = global_version;
    return value;
}

void Constant::set_value(int new_value) {
    value = new_value;
    global_version++;
}