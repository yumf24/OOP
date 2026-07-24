#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "event.h"

using namespace std;

class Chocolate: public EventInterface {
    EventInterface* last_zoo;
    bool is_cho;

public:
    Chocolate(): EventInterface(), last_zoo(nullptr), is_cho(true) {}

    void zoo(EventInterface* rhs) override;
    virtual void shop(EventInterface* rhs) override;
    virtual void birthday() override;
};

class Strawberry: public EventInterface {
    vector<EventInterface*> all_shop;

public:
    Strawberry(): EventInterface() {
    }

    void zoo(EventInterface*) override;
    virtual void shop(EventInterface*) override;
    virtual void birthday() override;
};