#include <iostream>
#include <istream>
using namespace std;

class Int {
private:
    int high, low;
public:
    Int(int h, int l):high(h),low(l) {}
    Int operator+(Int &a) {
        return Int(this->high+a.high, this->low+a.low);
    }
    Int operator-(Int &a) {
        return Int(this->high-a.high, this->low-a.low);
    }
    bool operator==(Int &a) {
        return (this->high == a.high && this->low == a.low);
    }
    bool operator<(Int &a) {
        if(this->high < a.high) {
            return true;
        }
        else if(this->high > a.high) {
            return false;
        }
        else {
            if(this->low < a.low) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    Int operator-() {
        return Int(-this->high, -this->low);
    }
    // 前置
    Int operator++() {
        this->high ++;
        this->low ++;
        return Int(high, low);
    }
    // 后置
    Int operator++(int ) {
        Int temp(high, low);
        this->high ++;
        this->low ++;
        return temp;
    }
    // 前置
    Int operator--() {
        this->high --;
        this->low --;
        return Int(high, low);
    }
    // 后置
    Int operator--(int ) {
        Int temp(high, low);
        this->high --;
        this->low --;
        return temp;
    }

    Int operator=(Int &a) {
        this->high = a.high;
        this->low = a.low;
        return Int(high, low);
    }
    Int operator+=(Int &a) {
        this->high += a.high;
        this->low += a.low;
        return Int(high, low);
    }

    friend istream& operator>>(istream& in, Int &a);
    friend ostream& operator<<(ostream& out,const Int &a);
};

istream& operator>>(istream& in, Int &a) {
    in >> a.high >> a.low;
    return in;
}

ostream& operator<<(ostream& out,const Int &a) {
    out << (a.high*(1e8) + a.low) << endl;
    return out;
}
int main() {
    return 0;
}
