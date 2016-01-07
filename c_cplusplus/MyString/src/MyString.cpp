/*
 * MyString.cpp
 *
 *  Created on: 2016Äê1ÔÂ5ÈÕ
 *      Author: zhonghuiping
 */
#include "MyString.h"
MyString::MyString() {
	len = 0;
	p = NULL;
}
MyString::MyString(const char *str) {
	if (str == NULL) {
		len = 0;
		p = NULL;
	} else {
		len = strlen(str) + 1;
		p = new char[len];
		strcpy(p, str);
	}
}
MyString::MyString(const char *str1, const char *str2) {
	if (str1 == NULL) {
		if (str2 == NULL) {
			len = 0;
			p = NULL;
		} else {
			len = strlen(str2) + 1;
			p = new char[len];
			strcpy(p, str2);
		}
	} else {
		if (str2 == NULL) {
			len = strlen(str1) + 1;
			p = new char[len];
			strcpy(p, str1);
		} else {
			len = strlen(str1) + strlen(str2) + 1;
			p = new char[len];
			strcpy(p, str1);
			strcat(p, str2);
		}
	}
}
MyString::MyString(const MyString &ms) {
	if (p == ms.p)
		return;
	if (p != NULL) {
		delete[] p;
		p = NULL;
		len = 0;
	}
	len = ms.len;
	p = new char[len];
	strcpy(p, ms.p);

}
MyString::~MyString() {
	if (p != NULL) {
		delete[] p;
		p = NULL;
		len = 0;
	}
}

void MyString::getP() {
	cout << p << endl;
}
MyString& MyString::operator=(const MyString &ms) {
	if (p != NULL && p != ms.p) {
		delete[] p;
		p = NULL;
		len = 0;
	}

	len = ms.len;
	p = new char[len];
	strcpy(p, ms.p);
	return *this;
}
MyString& MyString::operator=(const char *str) {
	if (p != NULL) {
		delete[] p;
		p = NULL;
		len = 0;
	}

	len = strlen(str) + 1;
	p = new char[len];
	strcpy(p, str);

	return *this;
}
MyString MyString::operator+(const MyString &ms) {
	return MyString(p, ms.p);
}
MyString MyString::operator+(const char *str) {

	return MyString(p, str);
}
bool MyString::operator==(const MyString &ms) {
	if (strcmp(p, ms.p) == 0)
		return true;
	return false;
}
bool MyString::operator==(const char *str) {
	if (strcmp(p, str) == 0)
		return true;
	return false;
}
bool MyString::operator!=(const MyString &ms) {
	if (strcmp(p, ms.p) != 0)
		return true;
	return false;
}
bool MyString::operator!=(const char *str) {
	if (strcmp(p, str) != 0)
		return true;
	return false;
}
char& MyString::operator[](const int index) {
	return p[index];
}
MyString& MyString::operator+=(const MyString &ms) {
	*this = MyString(p, ms.p);
	return *this;
}
MyString& MyString::operator+=(const char *str) {

	*this = MyString(p, str);
	return *this;
}
ostream& operator<<(ostream &cou, const MyString &ms)
{
	cou<<ms.p;
}
