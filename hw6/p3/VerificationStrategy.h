#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy: public VerificationStrategy {
	std::string verify(std::string mes) override {
		return mes.substr(0,3);
	}
};

class IntervalStrategy: public VerificationStrategy {
	std::string verify(std::string mes) override {
		std::string result;
		for(int i=0; i < mes.size(); i+=2) {
			result += mes[i];
		}
		return result;
	}
};