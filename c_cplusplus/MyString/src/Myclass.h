/*
 * Myclass.h
 *
 *  Created on: 2015��12��24��
 *      Author: zhonghuiping
 */
#pragma once
class Myclass {
public:
	Myclass() {
	}
	Myclass(const char *p);
	Myclass(const Myclass &my);
	void printInfo();
	~Myclass();
private:
	int len;
	char *p;
};

