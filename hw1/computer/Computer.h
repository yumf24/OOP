#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>

class Computer {
private:
    std::string name;
    int num;
    int price;
public:
    Computer() {};
    Computer(std::string name_new, int n, int pri): name(name_new), num(n), price(pri){}
    void setPrice(int new_price);
    Computer operator--();
    Computer operator++();
    Computer operator=(const Computer &a);
    bool operator<(const Computer &com);

    friend std::ostream& operator<<(std::ostream &out, const Computer& c);
};

std::ostream& operator<<(std::ostream &out, const Computer& c);
#endif