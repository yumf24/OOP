#include <iostream>
#include "Computer.h"

using namespace std;

void Computer::setPrice(int new_price) {
    price = new_price;
}

Computer Computer::operator--() {
    if(num > 0) num--;
    return Computer(name, num, price);
}

Computer Computer::operator++() {
    num++;
    return Computer(name, num, price);
}

bool Computer::operator<(const Computer &com) {
    if(this->num < com.num) return true;
    else if(num > com.num) return false;
    else {
        if(this->price < com.price) return true;
        else return false;
    }
}

Computer Computer::operator=(const Computer &a) {
    name = a.name;
    num = a.num;
    price = a.price;
    return *this;
}


ostream& operator<<(ostream &out, const Computer& c) {
    out << c.name << "-" << "num-" << c.num << "-price-" << c.price;
    return out;
}