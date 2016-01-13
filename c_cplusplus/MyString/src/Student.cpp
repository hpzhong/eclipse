/*
 * Student.cpp
 *
 *  Created on: 2015年12月24日
 *      Author: zhonghuiping
 */
#include "Student.h"
#include <iostream>
using namespace std;

void Student::printinfo(void) {
	cout << (sex ? "His" : "Her") << " name is " << name << endl;
	cout << name << "'s age is " << age << endl;
}

Student::Student() {
	cout << "Student init default" << endl;
}

Student::Student(string name, int age = 100, bool sex = true) {
	this->name = name;
	this->age = age;
	this->sex = sex;
	cout << "Student init " << endl;
}

void Student::setAge(int age) {
	this->age = age;
}

int Student::getAge(void) {
	return age;
}

void Student::setName(string name) {
	this->name = name;
}

string Student::getName(void) {
	return name;
}

void Student::setSex(bool sex) {
	this->sex = sex;
}

bool Student::getSex(void) {
	return sex;
}
Student::~Student() {
	cout << "Student end" << endl;
}

