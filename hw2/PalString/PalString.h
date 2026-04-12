#ifndef __PALSTRING_H
#define __PALSTRING_H

#include <cstring>
#include <iostream>
using namespace std;
class PalString {
private:
    char* str;

public:
    PalString(const char* new_str) {
        // create a new address for str, one more bit for the \0
        int new_str_len = strlen(new_str);
        str = new char[2*new_str_len + 1];
        str[2*new_str_len] = '\0';
        for(int i = 0; i < new_str_len;i++) {
            str[i] = new_str[i];
            str[2*new_str_len-i-1] = new_str[i];
        }
    }
    ~PalString() {
        delete [] str;
    }
    PalString(const PalString & Pal) {
        str = new char[strlen(Pal.str)];
        strcpy(str, Pal.str);
    }
    char * getString() {
        return str;
    }
    void changeString(const char * new_str) {
        int new_str_len = strlen(new_str);
        str = new char[2*new_str_len + 1];
        str[2*new_str_len] = '\0';
        for(int i = 0; i < new_str_len;i++) {
            str[i] = new_str[i];
            str[2*new_str_len-i-1] = new_str[i];
        }
    }

    friend ostream& operator<<(ostream& out, const PalString& Pal);
};

ostream& operator<<(ostream& out, const PalString& Pal) {
    out << Pal.str;
    return out;
}


#endif