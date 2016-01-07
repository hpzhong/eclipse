/*
 * Myclass.h
 *
 *  Created on: 2015Äê12ÔÂ24ÈÕ
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

