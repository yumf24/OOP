#include "Course.h"
#include <iostream>

using namespace std; 


int main() {
	Course oop("Liu", 2, 99.6);
	cout << oop << endl;
	cout << static_cast<string>(oop) << endl;
	cout << static_cast<int>(oop) << endl;
	cout << static_cast<double>(oop) << endl;
	return 0;
}
