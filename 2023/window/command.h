#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
#include <vector>
using namespace std;

class ClearAll {
    // TODO
    list<shared_ptr<Checkbox>> l;
public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox): l(checkbox) {}
    void operator()() {

        list<pair<string, bool>> oldState;
        for(auto i : l) {
            if(i->get_selected()) {
                oldState.push_back(make_pair(i->getName(), i->get_selected()));
                i->setSelect(false);
            }
        }
        l.front()->getParent()->saveOldState(oldState); 
    }
};

class SelectAll {
    // ...
    list<shared_ptr<Checkbox>> l;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox): l(checkbox) {}
    void operator()(){
        list<pair<string, bool>> oldState;
        for(auto i : l) {
            if(!i->get_selected()) {
                oldState.push_back(make_pair(i->getName(), i->get_selected()));
                i->setSelect(true);
            }
        }
        l.front()->getParent()->saveOldState(oldState); 
    }
};

class Submit {
    // ...
    list<shared_ptr<Checkbox>> l;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox): l(checkbox) {}
    void operator()() {

        for(auto i : l) {
            if(!(i->get_selected())) {
                // 未选中
                cout << i->getName() << " is not selected" << endl;
            }
            else {
                cout << i->getName() << " is selected" << endl;
            }
        }

    }
};