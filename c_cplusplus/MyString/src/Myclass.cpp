/*
 * Myclass.cpp
 *
 *  Created on: 2015Äê12ÔÂ24ÈÕ
 *      Author: zhonghuiping
 */
#include "Myclass.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Myclass::Myclass(const char *p) {
	len = strlen(p);
	this->p = (char *) malloc(strlen(p) + 1);
	strcpy(this->p, p);
	cout << "Myclass begin" << endl;
}

Myclass::Myclass(const Myclass &my) {
	p = strdup(my.p);
	len = my.len;
}

void Myclass::printInfo() {
	cout << p << endl;
}

Myclass::~Myclass() {
	if (p)
		free(p);
	cout << "Myclass end" << endl;
}

