//============================================================================
// Name        : main.cpp
// Author      : kabir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include "Myclass.h"
#include "Student.h"
#include "MyString.h"
using namespace std;
int func1() {
	Student t1;
	t1.setAge(31);
	t1.setName("James");
	t1.setSex(false);
	t1.printinfo();
	return 0;
}

int main(int argc, char **argv) {
#if 0
	func();
	Myclass b("Caber");
	Myclass c = b;
	b.printInfo();
#else
	MyString my = "Hello, c++";
	MyString ms = "Hello, C++";
	my = my + my + my;
	cout<<my<<endl;
#endif
	return 0;
}
