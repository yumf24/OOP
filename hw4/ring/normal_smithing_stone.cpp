
#include "normal_smithing_stone.h"
#include <iostream>

NormalSmithingStone::NormalSmithingStone(int level): SmithingStone(level) {
    std::cout << "Normal smithing stone " << level << " was created." << std::endl;
}

NormalSmithingStone::~NormalSmithingStone() {
    std::cout << "Normal smithing stone " << get_level() << " was destroyed." << std::endl;
}

void NormalSmithingStone::add_amount(int amount) {
    // 将amount分为+和-两种
    SmithingStone::add_amount(amount);
    if(amount >= 0) {
        std::cout << "Normal smithing stone " << get_level() << " was added with " << amount << "." << std::endl;
    } else {
        std::cout << "Normal smithing stone " << get_level() << " was subtracted with " << -amount << "." << std::endl;
    }
}

bool NormalSmithingStone::greater_equal(int need) const {
    return SmithingStone::greater_equal(need);
}

int NormalSmithingStone::get_level() const {
    return SmithingStone::get_level();
}