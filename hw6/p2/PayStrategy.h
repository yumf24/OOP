#pragma once
#include <string>

class PayStrategy {								
public:
	virtual double pay(std::string name, double money) = 0;
};


class NormalStrategy : public PayStrategy {	
	double pay(std::string name, double money) override {
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
	double pay(std::string name, double money) override {
		if(money <= 10000) {
			return (money-10);
		} else {
			double service = money/1000;
			if(service > 20) service = 20;
			return (money-service);
		}
	}

};

class BitcoinStrategy : public PayStrategy {	
	double pay(std::string name, double money) override {
		money -= (name.size()+8)*0.01;
		return money;
	}
};
