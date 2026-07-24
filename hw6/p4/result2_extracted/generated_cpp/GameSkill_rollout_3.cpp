#include "GameSkill.h"
#include <iostream>

int LegacySkillAdapter::cast() {
    return _legacy_skill->doMagicAttack();
}

int MpChecker::cast() {
    if (mpInit >= currentMp) {
        mpInit -= currentMp;
        return _iskill->cast();
    } else {
        std::cout << "[MP insufficient!]" << std::endl;
        return 0;
    }
}

int CritBuff::cast() {
    std::cout << "[Critical hit!]" << std::endl;
    return _iskill->cast() * 2;
}

int PoisonBuff::cast() {
    std::cout << "[Poison hit!]" << std::endl;
    return _iskill->cast() + 15;
}