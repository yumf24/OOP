#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

using std::string;

class Calculator {								
private:
    OccupationStrategy* _os;
    PayStrategy* _ps;
public:
    Calculator(OccupationStrategy* os, PayStrategy* ps): _os(os), _ps(ps) {}
    double getSalary(double base, double bonus, double level) {
        return (_os->getSalary(base, bonus, level));
    }
    double pay(string name, double salary) {
        return (_ps->pay(name, salary));
    }

    ~Calculator() {
    }
};