#pragma once
#include <functional>
using namespace std;

class Click {
private:
    // TODO
    function<void()> _f;
public:
    // TODO
    Click() {

    }
    // TODO
    void setClickCommand(std::function<void()> f) {
        _f = f;
    }
    // TODO
    virtual void click() {
        if(_f) _f();
    }
};
class DoubleClick {
private:
    // TODO
    function<void()> _f;
public:
    // TODO
    DoubleClick() {

    }
    // TODO
    void setDoubleClickCommand(std::function<void()> f) {
        _f = f;
    }
    // TODO
    virtual void doubleClick() {
        if(_f) _f();
    }
};