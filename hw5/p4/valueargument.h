#pragma once
#include "iargument.h"
#include "string"
#include "optional"
#include <iostream>
#include <sstream>
#include <type_traits>



template<typename T>
class ValueArgument : public IArgument {
public:
    std::optional<T> value;
    T default_value;
    ValueArgument(char s, const std::string& l, const std::string& d, T def_val) : IArgument(s, l, d), default_value(def_val) {
        // do something
    }
    bool parse(const std::vector<std::string>& args, size_t& index) override {
        // do something
        
        // check whether the index is the end of args
        if(index == (args.size() - 1)) {
            // parse error
            std::string error_info = "Error: Argument ";
            error_info += long_name_;
            error_info += " requires a value.";
            std::cout << error_info << std::endl;
            return false;
        }

        auto param_next = args[index+1];
        if(param_next[0] == '-') {
            // parse error
            std::string error_info = "Error: Argument ";
            error_info += long_name_;
            error_info += " requires a value.";
            std::cout << error_info << std::endl;
            return false;
        }

        // parse successfully
        std::stringstream ss;
        ss << param_next;
        T temp;
        ss >> temp;
        value = temp;

        index++;
        return true;
    }
    std::string get_info() const override {
        // do something
        std::string info = "  ";
        info += "-";
        info += short_name_;
        info += ", ";
        info += ("--"+long_name_);
        info += "=<value>\t";
        info += description_;
        info += " (default: ";

        std::ostringstream oss;
        oss << info << default_value << ")";
        return oss.str();
    }
};