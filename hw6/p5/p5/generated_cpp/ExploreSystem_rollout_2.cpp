#include <string>
#define private public
#include "ExploreSystem.h"
#undef private

#include <iostream>

Tool::Tool(float toolValue) : _toolValue(toolValue), _seal(false) {}

float Tool::getToolValue() {
    if (_seal) return -1;
    return _toolValue;
}

void Tool::setSeal() {
    _seal = true;
}

Weapon::Weapon(float weaponValue) : _weaponValue(weaponValue) {}

SwordWeapon::SwordWeapon(float weaponValue) : Weapon(weaponValue) {}

float SwordWeapon::getWeaponValue(int level) {
    return _weaponValue - level;
}

void SwordWeapon::enhanceWeapon() {
    _weaponValue *= 1.05;
}

StaffWeapon::StaffWeapon(float weaponValue) : Weapon(weaponValue) {}

float StaffWeapon::getWeaponValue(int level) {
    if (level > _weaponValue) return 0;
    return _weaponValue / 2.0;
}

void StaffWeapon::enhanceWeapon() {
    _weaponValue *= 1.1;
}

DaggerWeapon::DaggerWeapon(float weaponValue) : Weapon(weaponValue) {}

float DaggerWeapon::getWeaponValue(int level) {
    return level;
}

void DaggerWeapon::enhanceWeapon() {
    // 匕首强化无效果
}

float Player::getWeaponValue(int level) {
    return weapon->getWeaponValue(level);
}

float Player::getToolValue() {
    return tool->getToolValue();
}

void Player::enhanceWeapon() {
    weapon->enhanceWeapon();
}

void Player::sealTool() {
    tool->setSeal();
}

NormalDungeon::NormalDungeon(int level) : Dungeon(level) {}

float NormalDungeon::startExplore(Player* player) {
    std::cout << "Enter dungeon, level: " << _level << std::endl;
    return player->getWeaponValue(_level) + player->getToolValue();
}

ToolSealDungeon::ToolSealDungeon(int level) : Dungeon(level) {}

float ToolSealDungeon::startExplore(Player* player) {
    player->sealTool();
    std::cout << "Enter tool seal dungeon, tool disabled, level: " << _level << std::endl;
    return (player->getWeaponValue(_level) + player->getToolValue()) * 2;
}

WeaponEnhanceDungeon::WeaponEnhanceDungeon(int level) : Dungeon(level) {}

float WeaponEnhanceDungeon::startExplore(Player* player) {
    player->enhanceWeapon();
    std::cout << "Enter weapon enhance dungeon, weapon enhanced, level: " << _level << std::endl;
    return player->getWeaponValue(_level) + player->getToolValue();
}

Player* createPlayer(std::string weaponName, float weaponValue, std::string toolName) {
    Player* player = new Player();
    
    if (weaponName == "sword") player->weapon = new SwordWeapon(weaponValue);
    else if (weaponName == "staff") player->weapon = new StaffWeapon(weaponValue);
    else if (weaponName == "dagger") player->weapon = new DaggerWeapon(weaponValue);

    if (toolName == "torch") player->tool = new Tool(3);
    else if (toolName == "detector") player->tool = new Tool(6);
    else if (toolName == "toolkit") player->tool = new Tool(9);

    return player;
}

Dungeon* createDungeon(std::string dungeonName, int level) {
    if (dungeonName == "normal") return new NormalDungeon(level);
    else if (dungeonName == "toolseal") return new ToolSealDungeon(level);
    else if (dungeonName == "weaponenhance") return new WeaponEnhanceDungeon(level);
    return nullptr;
}