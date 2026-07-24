#pragma once

class OccupationStrategy {								
public:
	virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {
	double getSalary(double base, double bonus, double level) override {
		double result = base;
		if(60 <= level && level < 70) {
			result += bonus*0.6;
		} 
		else if(70 <= level && level < 80) {
			result += bonus*0.7;
		}
		else if(80 <= level && level <= 100) {
			result += bonus;
		}
		return result;
	}
};

class DeveloperStrategy : public OccupationStrategy {	
	double getSalary(double base, double bonus, double level) override {
		double result = base + bonus*(level/100);
		return result;
	}
};