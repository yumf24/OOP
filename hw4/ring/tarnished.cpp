#include "tarnished.h"
#include <algorithm>
#include <iostream>

using std::string, std::cout, std::endl;

Tarnished::Tarnished() {
    // 全部初始化为空指针
    std::fill(std::begin(normal_weapons), std::end(normal_weapons), nullptr);
    std::fill(std::begin(somber_weapons), std::end(somber_weapons), nullptr);
    std::fill(std::begin(normal_smithing_stones), std::end(normal_smithing_stones), nullptr);
    std::fill(std::begin(somber_smithing_stones), std::end(somber_smithing_stones), nullptr);
}

Tarnished::~Tarnished() {
    for(int i = 1; i < MAX_STONES; ++i) {
        if(normal_smithing_stones[i] != nullptr) delete normal_smithing_stones[i];
    }
    for(int i = 1; i < MAX_STONES; ++i) {
        if(somber_smithing_stones[i] != nullptr) delete somber_smithing_stones[i];
    }

    int i = 0;
    while (normal_weapons[i] != nullptr)
    {
        delete normal_weapons[i];
        ++i;
    }
    i = 0;
    while (somber_weapons[i] != nullptr)
    {
        delete somber_weapons[i];
        ++i;
    }
}

void Tarnished::pick_up_stone(int type, int level, int number) {
    if(type == 0) {
        // 普通锻造石
        if(normal_smithing_stones[level] == nullptr) {
            normal_smithing_stones[level] = new NormalSmithingStone(level);
        }
        normal_smithing_stones[level]->add_amount(number);
    }
    else if(type == 1) {
        // 失色锻造石
        if(somber_smithing_stones[level] == nullptr) {
            somber_smithing_stones[level] = new SomberSmithingStone(level);
        }
        somber_smithing_stones[level]->add_amount(number);
    }

}

void Tarnished::pick_up_weapon(int type, string name) {
    if(type == 0) {
        // 普通
        unsigned int weapons_num = 0;
        if(normal_weapons[0] != nullptr) 
            weapons_num = sizeof(normal_weapons) / sizeof(normal_weapons[0]);    
        normal_weapons[weapons_num] = new NormalWeapon(name);
    }
    else if(type == 1) {
        unsigned int weapons_num = 0;
        if(somber_weapons[0] != nullptr) 
            weapons_num = sizeof(somber_weapons) / sizeof(somber_weapons[0]);    
        somber_weapons[weapons_num] = new SomberWeapon(name);
    }
}

void Tarnished::upgrade_weapon(int target, string name) {
    // 找出对应的武器
    Weapon* pw = nullptr;
    int type = -1;


    // 从普通武器里面找
    int normal_weapons_num = 0;
    if(normal_weapons[0] != nullptr) normal_weapons_num = sizeof(normal_weapons) / sizeof(normal_weapons[0]);
    for(int i = 0; i < normal_weapons_num; ++i) {
        if(name == normal_weapons[i]->get_name()) {
            pw = normal_weapons[i];
            type = 0;
        }
    }
    // 找失色
    if(type != 0) {
        int somber_weapons_num = 0;
        if(somber_weapons[0] != nullptr) somber_weapons_num = sizeof(somber_weapons) / sizeof(somber_weapons[0]);
        for(int i = 0; i < somber_weapons_num; ++i) {
            if(name == somber_weapons[i]->get_name()) {
                pw = somber_weapons[i];
                type = 1;
            }
        }
    }

    // 如果没有这把武器
    if(type == -1) {
        cout << "You don't have the right!" << endl;
        return ;
    }
    // 将pw向下转换为对应的类型
    int curr_grade = -1;
    NormalWeapon* nw = nullptr;
    if(type == 0) {
        nw = static_cast<NormalWeapon*>(pw);
        curr_grade = nw->get_grade();
    }
    SomberWeapon* sw = nullptr;
    if(type == 1) {
        sw = static_cast<SomberWeapon*>(pw);
        curr_grade = sw->get_grade();
    }
    // 如果target不大于当前等级
    if(target <= curr_grade) {
        cout << "Stay calm!" << endl;
    }

    // 判断是否能够强化成功
    bool couldornot = true;
    int each_grade_needed[3] = {2,4,6};
    int lack_level = 0;
    if(type == 0) {
        int grade_temp = curr_grade;
        int curr_level = (grade_temp / 3 + 1);
        int prev_level = curr_level;
        int curr_level_needede_nums = 0;
        while (grade_temp < target && couldornot)
        {
            if(normal_smithing_stones[curr_level] == nullptr) {
                // 缺少这种等级的强化石，直接失败
                couldornot = false;
                lack_level = curr_level;
                break;
            }
            int remainder = grade_temp%3;
            curr_level_needede_nums += each_grade_needed[remainder];
            if(normal_smithing_stones[curr_level]->greater_equal(curr_level_needede_nums)) {
                // 暂时还够用
                grade_temp++;
                curr_level = (grade_temp / 3 + 1);
                if(prev_level != curr_level) {
                    // 步入了下一个等级
                    curr_level_needede_nums = 0;
                    prev_level = curr_level;
                }
            }
            else {
                // 强化失败
                lack_level = curr_level;
                couldornot = false;
            }
        }
    }
    else {
        int grade_temp = curr_grade;
        int curr_level = (grade_temp / 3 + 1);
        int prev_level = curr_level;
        int curr_level_needede_nums = 0;
        while (grade_temp < target && couldornot)
        {
            if(somber_smithing_stones[curr_level] == nullptr) {
                // 缺少这种等级的强化石，直接失败
                lack_level = curr_level;
                couldornot = false;
                break;
            }
            int remainder = grade_temp%3;
            curr_level_needede_nums += each_grade_needed[remainder];
            if(somber_smithing_stones[curr_level]->greater_equal(curr_level_needede_nums)) {
                // 暂时还够用
                grade_temp++;
                curr_level = (grade_temp / 3 + 1);
                if(prev_level != curr_level) {
                    // 步入了下一个等级
                    curr_level_needede_nums = 0;
                    prev_level = curr_level;
                }
            }
            else {
                // 强化失败
                lack_level = curr_level;
                couldornot = false;
            }
        }
    }

    if(couldornot == false) {
        // 强化失败
        if(type == 0) {
            cout << "Upgrade failed for lacking normal smithing stone " << lack_level << "." << endl;
        } 
        else {
            cout << "Upgrade failed for lacking somber smithing stone " << lack_level << "." << endl;
        }
        return ;
    }

    // 开始正式强化
    int before_upgrade_grade = curr_grade;
    int each_grade_needed[3] = {2,4,6};
    if(type == 0) {
        int curr_level = (curr_grade / 3 + 1);
        while (curr_grade < target)
        {
            int remainder = curr_grade%3;
            // 消耗强化石
            normal_smithing_stones[curr_level]->add_amount(each_grade_needed[remainder]);
            nw->upgrade();
            curr_grade++;
            curr_level = (curr_grade / 3 + 1);
        }
    }
    else {
        int curr_level = (curr_grade / 3 + 1);
        while (curr_grade < target)
        {
            int remainder = curr_grade%3;
            // 消耗强化石
            somber_smithing_stones[curr_level]->add_amount(each_grade_needed[remainder]);
            sw->upgrade();
            curr_grade++;
            curr_level = (curr_grade / 3 + 1);
        }
    }
    string old_extended_name = "";
    string new_extended_name = "+"+std::to_string(curr_grade);
    if(before_upgrade_grade != 0) old_extended_name = "+"+std::to_string(curr_grade);
    string old_name = name+old_extended_name;
    string new_name = name+new_extended_name;
    cout << "Upgrade " << old_name << " to " << new_name << " Successfully." << endl;
}