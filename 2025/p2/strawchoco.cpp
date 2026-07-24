#include <iostream>
#include <string>
#include <vector>

#include "strawchoco.h"

using namespace std;

void Chocolate::zoo(EventInterface* rhs) {
    this->last_zoo = rhs;
    increase_mood(5);
}

void Chocolate::shop(EventInterface* rhs) {
    increase_mood(1);
}

void Chocolate::birthday() {
    this->increase_mood(1);

    if(this->last_zoo != nullptr) {
        this->increase_mood(5);
        last_zoo->increase_mood(1);
    }
}


void Strawberry::zoo(EventInterface* rhs) {
    increase_mood(1);

    if(dynamic_cast<Chocolate*>(rhs) != nullptr) {
        increase_mood(5);
    }
}

void Strawberry::shop(EventInterface* rhs) {
    increase_mood(5);

    bool is_in = false;
    for(auto i : all_shop) {
        if(i == rhs) {
            is_in = true;
            break;
        }
    }

    if(!is_in) all_shop.push_back(rhs);

    if(dynamic_cast<Chocolate*>(rhs) != nullptr) {
        increase_mood(5);
    }
}

void Strawberry::birthday() {
    if(all_shop.size() != 0) {
        this->increase_mood(all_shop.size());
        for(auto i : all_shop) {
            i->increase_mood(1);
        }
    }

}
