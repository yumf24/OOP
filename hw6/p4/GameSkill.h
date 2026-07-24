#pragma once
#include "LegacySkill.h"

class ISkill {
public:
    virtual int cast() = 0;
    virtual ~ISkill() {}
};

class LegacySkillAdapter: public ISkill {
private:
    LegacySkill* _legacy_skill;

public:
    LegacySkillAdapter(LegacySkill* legacy_skill): _legacy_skill(legacy_skill) {}
    int cast() override;
};

class MpChecker: public ISkill {
private:
    ISkill* _iskill;
    int mpInit;
    int currentMp;

public:
    MpChecker(ISkill* new_iskill, int new_mpInit, int new_currentMp):
    _iskill(new_iskill), mpInit(new_mpInit), currentMp(new_currentMp) {}
    int cast() override;
};

class CritBuff: public ISkill {
private:
    ISkill* _iskill;
public:
    CritBuff(ISkill* iskill): _iskill(iskill) {}
    int cast() override;
};

class PoisonBuff: public ISkill {
private:
    ISkill* _iskill;
public:
    PoisonBuff(ISkill* iskill): _iskill(iskill) {}
    int cast() override;
};