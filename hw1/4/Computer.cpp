#include "Computer.h"
 
bool Computer::operator< (const Computer& computer) {
	if (num < computer.num)
		return true;
	if (num > computer.num)
		return false;

	if (price < computer.price)
		return true;
	if (price > computer.price)
		return false;

	return false;
}

Computer& Computer::operator++ (){
	num++;
	return *this;
}


Computer& Computer::operator-- (){
	if(num>0){
		num--;
	}
	return *this;
}

ostream& operator<< (ostream& out, const Computer& computer) {
	out << computer.name << "-num-" << computer.num << "-price-" << computer.price;
	return out;
}