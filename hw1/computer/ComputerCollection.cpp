#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ComputerCollection.h"
using namespace std;

Computer& ComputerCollection::operator[](string name) {

    // find the index of name in the name_vec
    for(int i = 0;i != name_vec.size();i++) {
        if(name == name_vec[i]) {
            return computer_vec[i];
        }
    }
    // not find the name in the name_vec
    std::cout << "Error!Not find the name " << name << std::endl;
    exit(1);
}

void swap_computer(Computer &a, Computer &b) {
    Computer temp;
    temp = a;
    a = b;
    b = temp;
}

void ComputerCollection::sortByScore() {
    // bubble sort
    int size = computer_vec.size();
    for(int k = 0;k < size-1;k++) {
        for(int j = 0;j < size-k-1;j++) {
            if(computer_vec[j] < computer_vec[j+1]) {
                swap(computer_vec[j], computer_vec[j+1]);
            }
        }
    }
}

istream& operator>>(istream& in, ComputerCollection& cc) {
    string s;
    in >> s;
    stringstream ss(s);
    string item;
    vector<string> temp_vec;
    for(int i = 0;i < 3;i++) {
        getline(ss, item, '-');
        temp_vec.push_back(item);
    }
    cc.computer_vec.push_back(Computer(temp_vec[0], atoi(temp_vec[1].data()), atoi(temp_vec[2].data())));
    cc.name_vec.push_back(temp_vec[0]);
    return in;
}

ostream& operator<<(ostream& out, const ComputerCollection& cc) {
    for(int i = 0;i < cc.computer_vec.size();i++ ) {
        out << cc.computer_vec[i] << endl;
    }
    return out;
}