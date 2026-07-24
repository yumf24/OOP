#pragma once
#include <memory>
#include <list>
#include "event.h"
#include <algorithm>
#include <vector>

using namespace std;

class Window;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
    // TODO
private:
    bool selected;
public:
    Checkbox(string name):Widget(name) , selected(false) {}

    void setSelect(bool flag) {
        selected = flag;
    }

    void click() override;
    bool get_selected() {
        return selected;
    }
};

class Window {

private:
    list<shared_ptr<Widget>> Widgets;
    vector<list<pair<string, bool>>> history;
    // TODO

public:
    // TODO

    void saveOldState(list<pair<string,bool>> toadd) {
        history.push_back(toadd);
    }

    shared_ptr<Widget> getPointerByName(string name) {
        for(auto i : Widgets) {
            if(i->getName() == name) {
                return i;
            }
        }
    }
    // TODO
    Widget& getElementByName(string name) {
        for(auto i : Widgets) {
            if(i->getName() == name) {
                return (*i);
            }
        }
    }
    // TODO
    bool addElement(shared_ptr<Widget> w) {
        for(auto i : Widgets) {
            if(w->getName() == i->getName()) {
                return false;
            }
        }
        Widgets.push_back(w);
        w->setParent(this);
        return true;
    }
    // TODO
    bool undo() {
        if(history.size() == 0) {
            return false;
        }
        else {
            list<pair<string, bool>> old = history.back();
            history.pop_back();

            for(auto i : old) {
                auto& check = dynamic_cast<Checkbox&>(getElementByName(i.first));
                check.setSelect(i.second);
            }
            return true;
        }
    }
};

void Checkbox::click() {
    list<pair<string, bool>> oldState;
    oldState.push_back(make_pair(getName(), selected));
    selected = (!selected);
    this->getParent()->saveOldState(oldState);
}