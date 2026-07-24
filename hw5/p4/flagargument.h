#pragma once
#include "iargument.h"
#include "string"

class FlagArgument : public IArgument {
public:
    bool value = false;
    FlagArgument(char s, const std::string& l, const std::string& d) : IArgument(s, l, d), value(false) {
        // do something
    }
    bool parse(const std::vector<std::string>& argv, size_t& index) override {
        // do something
        // just set the value to true
        value = true;
        return true;
    }
    std::string get_info() const override {
        // do something
        std::string info = "  ";
        info += "-";
        info += short_name_;
        info += ", ";
        info += ("--"+long_name_);
        info += "\t\t";
        info += description_;
        return info;

    }
    bool is_flag() const override {
        // do something
        return true;
    }
};