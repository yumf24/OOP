#pragma once
#include <string>


class Tool{
protected:
    float _toolValue;
    bool _seal;
public:
    Tool(float toolValue);
    float getToolValue();
    void setSeal();
};

class Weapon{
protected:
    float _weaponValue;
public:
    Weapon(float weaponValue);
    virtual float getWeaponValue(int level) = 0;
    virtual void enhanceWeapon() = 0;
};

class SwordWeapon: public Weapon {
public:
    SwordWeapon(float weaponValue);
    float getWeaponValue(int level) override;
    void enhanceWeapon() override;
};

class StaffWeapon: public Weapon {
public:
    StaffWeapon(float weaponValue);
    float getWeaponValue(int level) override;
    void enhanceWeapon() override;
};

class DaggerWeapon: public Weapon {
public:
    DaggerWeapon(float weaponValue);
    float getWeaponValue(int level) override;
    void enhanceWeapon() override;
};

class Player{
private:
    Weapon* weapon;
    Tool* tool;

public:
    Player(Weapon* _weapon, Tool* _tool): weapon(_weapon), tool(_tool){}
    float getWeaponValue(int level);
    float getToolValue();
    void enhanceWeapon();
    void sealTool();
};

class Dungeon{
protected:
    int _level;
public:
    Dungeon(int level): _level(level) {}
    virtual float startExplore(Player* player) = 0;
};

class NormalDungeon: public Dungeon{
public:
    NormalDungeon(int level);
    float startExplore(Player* player) override;
};

class ToolSealDungeon: public Dungeon{
public:
    ToolSealDungeon(int level);
    float startExplore(Player* player) override;
};

class WeaponEnhanceDungeon: public Dungeon{
public:
    WeaponEnhanceDungeon(int level);
    float startExplore(Player* player) override;
};



Player* createPlayer(std::string weaponName, float weaponValue, std::string toolName);
Dungeon* createDungeon(std::string dungeonName, int level);
