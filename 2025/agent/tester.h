#pragma once

#include "agent.h"
#include <iostream>
#include <string>

using namespace std;

class Tester: public Agent {
    char marker;
    int flag;
    int test_passed;
public:
    Tester(int id, std::string& codes): Agent(id, codes) {
        cin >> marker >> flag;
        test_passed = 0;
    }

    void action() {
        int nums = 0;
        for(auto i : codes) {
            if(marker == i) nums++;
        }
        if(nums % 2 == flag) {
            test_passed++;
        }
    }
    void report() {
        cout << "Tester " << get_agent_id() << ": " << test_passed << " tests passed" << endl;
    }
};