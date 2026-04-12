#pragma once
#include <string>
#include <iostream>
using namespace std;

const int MAX = 220; 
class CHugeInt {
// 在此处补充你的代码
private:
    string s;
    const int MAX_SIZE = 220;
public:
    // Construct Function
    CHugeInt(const int num);
    CHugeInt(const char *str);

    // operator reload function
    const CHugeInt operator+(int num) const;// class + num
    const CHugeInt operator+(const CHugeInt& right) const; // class + class 

    // reload ++
    CHugeInt& operator++(); // prefix ++
    CHugeInt operator++(int); // postfix ++

    // reload +=
    void operator+=(int num);

    // friend function
    // int + class
    friend const CHugeInt operator+(const int num, const CHugeInt right_class);
    // reload <<
    friend ostream & operator<<(ostream& out, const CHugeInt& right);
};