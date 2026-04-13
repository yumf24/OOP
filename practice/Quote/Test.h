#pragma once

#include <iostream>

using namespace std;

class Test {
public:
	int * buf; //// only for demo.
	Test() {
		buf = new int[10]; //申请一块内存
		cout << "Test(): this->buf @ " << hex << buf << endl;
	}
	~Test() {
		cout << "~Test(): this->buf @ " << hex << buf << endl;
		if (buf) delete[] buf;
	}
	Test(const Test& t) : buf(new int[10]) {
		for(int i=0; i<10; i++) 
			buf[i] = t.buf[i]; //拷贝数据
		cout << "Test(const Test&) called. this->buf @ "
			<< hex << buf << endl;
	}
	Test(Test&& t) : buf(t.buf) { //直接复制地址，避免拷贝
		cout << "Test(Test&&) called. this->buf @ "
			<< hex << buf << endl;
		t.buf = nullptr; //将t.buf改为nullptr，使其不再指向原来内存区域
	}
    Test& operator= (const Test& right) {
        if (this == &right)  cout << "same obj!\n";
        else {
            for(int i=0; i<10; i++)
                buf[i] = right.buf[i];  //拷贝数据
        cout << "operator=(const Test&) called.\n";
    }
        return *this;
    }

    Test& operator= (Test&& right) {
        if (this == &right)  cout << "same obj!\n";
        else {	
            this->buf = right.buf;  //直接赋值地址
            right.buf = nullptr;
        cout << "operator=(Test&&) called.\n";
    }
        return *this;
    }

};
