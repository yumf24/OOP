#include "CHugeInt.h"
#include <string>
#include <algorithm>

using namespace std;


// Construct Function
CHugeInt::CHugeInt(const int num) {
    s.reserve(MAX_SIZE);
    s = to_string(num);
}

CHugeInt::CHugeInt(const char *str) {
    s.reserve(MAX_SIZE);
    s = str;
}

// operator reload function

// HelpFunction, add two string
void MyAddForString(string& result, string& num_str) {

    std::reverse(result.begin(), result.end());
    std::reverse(num_str.begin(), num_str.end());
    // process every element of num_str
    char temp;
    int add_one = 0;
    for(size_t i = 0;i < result.size();i++) {
        if(i < num_str.size())
            temp = num_str[i] + result[i] + add_one - '0';
        else 
            temp = result[i] + add_one;

        if(temp > '9') {
            // more than 9
            temp -= 10;
            add_one = 1;
        }
        else {
            add_one = 0;
        }
        result[i] = temp;
    }
    if(add_one == 1) {
        // 还得进一位
        result.push_back('1');
    }
    std::reverse(result.begin(), result.end());
}


// class + num
const CHugeInt CHugeInt::operator+(int num) const {
    string num_str = to_string(num);
    string result;
    if(s.size() > num_str.size()) {
        result = s;
    } else {
        result = num_str;
        num_str = s;
    }

    MyAddForString(result, num_str);
    return CHugeInt(result.c_str());
}

// class + class
const CHugeInt CHugeInt::operator+(const CHugeInt& right) const {
    string result, num_str;
    if(s.size() > right.s.size() )
    {
        result = s;
        num_str = right.s;
    }
    else {
        result = right.s;
        num_str = s;
    }
    MyAddForString(result, num_str);

    return CHugeInt(result.c_str());
}

// reload ++

// Help Function, ++ for a string
void MyPlus(string& str) {
    std::reverse(str.begin(), str.end());
    for(size_t i = 0;i < str.size();i++) {
        str[i] += 1;
        if(str[i] <= '9') {
            break;
        }
        str[i] = '0';
        if(i == (str.size()-1)) {
            // the last element, but still to add one
            str.push_back('1');
        }
    }
    std::reverse(str.begin(), str.end());
}

// prefix ++
CHugeInt& CHugeInt::operator++() {
    MyPlus(s);
    return *this;
}

// postfix ++
CHugeInt CHugeInt::operator++(int) {
    CHugeInt temp(s.c_str());
    MyPlus(s);
    return temp;
}

// reload +=
void CHugeInt::operator+=(int num) {
    string num_str = to_string(num);
    string result;
    if(s.size() > num_str.size()) {
        result = s;
    } else {
        result = num_str;
        num_str = s;
    }
    MyAddForString(result, num_str);
    s = result;
}

// friend function
// int + class
const CHugeInt operator+(const int num, const CHugeInt right_class) {
    string num_str = to_string(num);
    string result;
    if(right_class.s.size() > num_str.size()) {
        result = right_class.s;
    } else {
        result = num_str;
        num_str = right_class.s;
    }

    MyAddForString(result, num_str);
    return CHugeInt(result.c_str());
}
// reload <<
ostream & operator<<(ostream& out, const CHugeInt& right) {
    out << right.s;
    return out;
}