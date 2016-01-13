/*
 * Student.h
 *
 *  Created on: 2015年12月24日
 *      Author: zhonghuiping
 */

#pragma once
#include <string>
class Student {

public:
	Student();
	Student(std::string, int, bool);
	void setAge(int);
	int getAge(void);
	void setName(std::string);
	std::string getName(void);
	void setSex(bool);
	bool getSex(void);
	void printinfo(void);
	~Student();
private:
	int age;
	std::string name;
	bool sex;
};

