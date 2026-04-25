#pragma once
#include "smithing_stone.h"

class SomberSmithingStone: public SmithingStone {
public:
    void add_amount(int amount);
    bool greater_equal(int need) const;
    int get_level() const;
    SomberSmithingStone(int level);
    ~SomberSmithingStone();
};