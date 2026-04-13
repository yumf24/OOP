#include "ComputerCollection.h"
#include <algorithm>

istream& operator>> (istream& in, ComputerCollection& cc)
{
	string temp;
	in >> temp;
	string name = "";
	
	int i = 0;
	int num = 0;
	for (; i < temp.length(); ++i) {
		if (temp[i] == '-') {
			++i;
			num = int(temp[i] - '0');
			++i;
			break;
		}
		name += temp[i];
	}
	for (; i < temp.length(); ++i) {
		if (temp[i] == '-') {
			++i;
			break;
		}
		num = num * 10 + int(temp[i] - '0');
	}
	
	int price = 0;
	for (; i < temp.length(); ++i) {
		price = price * 10 + int(temp[i] - '0');
	}

	Computer* p = cc.has_name(name);
	if (p == nullptr) {
		p = new Computer();
		cc.computers[cc.computerNum] = p;
		cc.computerNum++;
	}
	p->addInfo(name, num, price);
	
	return in;
}

ostream& operator<< (ostream& out, const ComputerCollection& cc)
{
	for (int i = 0; i < cc.computerNum; ++i) {
		out << *(cc.computers[i]) << endl;
	}
	return out;
}

Computer& ComputerCollection::operator[](const string& name)
{
	return *(this->has_name(name));
}
