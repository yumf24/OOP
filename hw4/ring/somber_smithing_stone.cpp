#include "somber_smithing_stone.h"
#include <iostream>

SomberSmithingStone::SomberSmithingStone(int level): SmithingStone(level) {
    std::cout << "Somber smithing stone " << level << " was created." << std::endl;
}

SomberSmithingStone::~SomberSmithingStone() {
    std::cout << "Somber smithing " << get_level() << " was destroyed." << std::endl;
}

void SomberSmithingStone::add_amount(int amount) {
    // 将amount分为+和-两种
    SmithingStone::add_amount(amount);
    if(amount >= 0) {
        std::cout << "Somber smithing stone " << get_level() << " was added with " << amount << "." << std::endl;
    } else {
        std::cout << "Somber smithing stone " << get_level() << " was subtracted with " << amount << "." << std::endl;
    }
}

bool SomberSmithingStone::greater_equal(int need) const {
    return SmithingStone::greater_equal(need);
}

int SomberSmithingStone::get_level() const {
    return SmithingStone::get_level();
}