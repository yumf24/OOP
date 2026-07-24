#pragma once
#include "flagargument.h"
#include "valueargument.h"

#include <memory>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

class ArgParser {
private:
    std::string program_description_;
    std::vector<std::unique_ptr<IArgument>> arguments_;
    std::map<std::string, IArgument*> long_name_map_;
    std::map<char, IArgument*> short_name_map_;
    bool help_wanted_ = false;

public:
    ArgParser(const std::string& description) : program_description_(description) {
        addFlag('h', "help", "Show this help message.");
    }

    void addFlag(char s, const std::string& l, const std::string& d) {
        // do something
        FlagArgument* fa = new FlagArgument(s, l, d);
        long_name_map_[l] = fa;
        short_name_map_[s] = fa;
        std::unique_ptr<IArgument> up(fa);
        arguments_.push_back(std::move(up));
    }
    template<typename T>
    void addValue(char s, const std::string& l, const std::string& d, T def_val) {
        // do something
        ValueArgument<T>* va = new ValueArgument<T>(s, l, d, def_val);
        long_name_map_[l] = va;
        short_name_map_[s] = va;
        std::unique_ptr<IArgument> up(va);
        arguments_.push_back(std::move(up));
    }
    bool parse(int argc, char* argv[]) {
        // do something
        const std::vector<std::string> args(argv+1, argv+argc);

        for(size_t i = 0; i < (argc-1); i++) {
            std::string param = args[i];
            if(param[0] == '-') {
                if(param[1] == '-') {
                    // long name
                    auto true_param = param.substr(2);
                    if(long_name_map_.count(true_param) == 0) {
                        // error parse
                        std::cout << "Error: Unknown argument: " << param << std::endl;
                        return false;
                    } else {
                        // parse long name
                        if(!long_name_map_[true_param]->parse(args, i)) {
                            // the only error case is that the value param parse error
                            // the error info is cout by the ValeArgument.parse()
                            return false;
                        }
                    }
                }
                else {
                    // short name
                    auto true_param = param.substr(1);
                    if(true_param.size() != 1 || short_name_map_.count(true_param[0]) == 0) {
                        // error parse
                        std::cout << "Error: Unknown argument: " << param << std::endl;
                        return false;
                    } else {
                        // parse short name
                        if(!short_name_map_[true_param[0]]->parse(args, i)) {
                            // the only error case is that the value param parse error
                            // the error info is cout by the ValeArgument.parse()
                            return false;
                        }
                    }
                }
            }
        }
        // check the -h --help flag
        auto lit = long_name_map_.find("help");
        if(lit != long_name_map_.end()) {
            auto *pf = dynamic_cast<FlagArgument*>(lit->second);
            if(pf->value) help_wanted_ = true;
        }
        return true;
    }

    template<typename T>
    std::optional<T> get(const std::string& name) const {
        // do something.
        auto it = long_name_map_.find(name);
        if(it == long_name_map_.end()) {
            return std::nullopt;
        }

        auto* pb = it->second;
        if constexpr (std::is_same_v<T, bool>) {
            if(pb->is_flag()) {
                auto *pf = dynamic_cast<FlagArgument*>(pb);
                return pf->value;
            } else {
                auto *pv = dynamic_cast<ValueArgument<T>*>(pb);
                auto value = pv->value.value_or(pv->default_value);
                return value;
            }
        } else {
            auto *pv = dynamic_cast<ValueArgument<T>*>(pb);
            auto value = pv->value.value_or(pv->default_value);
            return value;
        }

    }

    bool wantsHelp() const { return help_wanted_; }
    void printHelp() const {
        std::cout << program_description_ << "\n\nUsage:\n";
        for (const auto& arg : arguments_) {
            std::cout << arg->get_info() << std::endl;
        }
    }
};