#include "agent.h"
#include "coder.h"
#include "tester.h"
#include <iostream>
#include <string>

using namespace std;


Agent* Agent::create_agent(int agent_type, int id, std::string& codes) {
    if(agent_type == 0) {
        // Coder
        Agent* agent = new Coder(id, codes);
        return agent;
    }
    else {
        Agent* agent = new Tester(id, codes);
        return agent;
    }

}