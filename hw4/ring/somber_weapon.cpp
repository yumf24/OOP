#include "somber_weapon.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

SomberWeapon::SomberWeapon(string name): Weapon(name), grade(0) {
    cout << "Somber weapon " << name << " was created." << endl;
}

SomberWeapon::~SomberWeapon() {
    string extended_name = "";
    if(grade != 0) extended_name = "+"+std::to_string(grade);
    cout << "Somber weapon " << get_name()+extended_name << " was destroyed." << endl;
}

string SomberWeapon::get_name() const {
    return Weapon::get_name();
}

int SomberWeapon::get_level() const {
    return Weapon::get_level();
}

int SomberWeapon::get_grade() const {
    return grade;
}

void SomberWeapon::upgrade() {
    Weapon::upgrade();
    string old_extended_name = "", new_extended_name = "";
    if(grade != 0) old_extended_name = "+" + std::to_string(grade);
    new_extended_name = "+" + std::to_string(++grade);
    string base_name = get_name();
    string old_name = base_name+old_extended_name, new_name = base_name+new_extended_name;
    cout << "Somber weapon " << old_name << " was upgraded to " << new_name << "." << endl;
}