#pragma once

#include "agent.h"
#include <iostream>
#include <string>

using namespace std;

class Coder: public Agent {
    int char_coded;
public:
    Coder(int id, std::string& codes): Agent(id, codes) {
        char_coded = 0;
    }

    void action() {
        string new_codes; 
        cin >> new_codes;
        codes += new_codes;
        char_coded += new_codes.size();
    }
    void report() {
        cout << "Coder " << get_agent_id() << ": " << char_coded << " characters coded" << endl;
    }
};