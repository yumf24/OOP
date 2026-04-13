#ifndef COMPUTERCOLLECTION_H
#define COMPUTERCOLLECTION_H

#include <vector>
#include "Computer.h"
using namespace std;

class ComputerCollection {
private:
    std::vector<Computer> computer_vec;
    std::vector<string> name_vec;

public:
    Computer& operator[](string name);
    void sortByScore();

    friend istream& operator>>(istream&in, ComputerCollection& cc);
    friend ostream& operator<<(ostream&out ,const ComputerCollection& cc);
};

istream& operator>>(istream&in, ComputerCollection& cc);
ostream& operator<<(ostream&out ,const ComputerCollection& cc);
#endif
