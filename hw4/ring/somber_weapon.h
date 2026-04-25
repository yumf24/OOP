#pragma once
#include "weapon.h"
#include <string>
using std::string;

class SomberWeapon: public Weapon {
    int grade;
public:
    string get_name() const;
    int get_level() const;
    void upgrade();
    int get_grade() const;

    SomberWeapon(string name);
    ~SomberWeapon();

};