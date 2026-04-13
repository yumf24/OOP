#pragma once

#include <string>
#include <iostream>
using namespace std;

class Course {
    string Name;
    int Credit;
    double Diff;

public:
    Course(string Name,int Credit,double Diff): Name(Name), Credit(Credit), Diff(Diff) {}
    friend ostream & operator<<(ostream& out, const Course& right);
    explicit operator string() {
        return Name;
    }
    explicit operator int() {
        return Credit;
    }
    explicit operator double() {
        return Diff;
    }
};

ostream & operator<<(ostream& out, const Course& right) {
    cout << right.Name << endl;
    cout << right.Credit << endl;
    cout << right.Diff << endl;
    return out;
}