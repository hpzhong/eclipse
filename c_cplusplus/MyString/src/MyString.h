/*
 * MyString.h
 *
 *  Created on: 2016年1月5日
 *      Author: zhonghuiping
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class MyString {
public:
	MyString();
	MyString(const char *);
	MyString(const MyString &);
	~MyString();

	void getP();

	MyString& operator=(const MyString &);
	MyString& operator=(const char *);
	MyString operator+(const MyString &);
	MyString operator+(const char *);
	MyString& operator+=(const MyString &);
	MyString& operator+=(const char *);
	bool operator==(const MyString &);
	bool operator==(const char *);
	bool operator!=(const MyString &);
	bool operator!=(const char *);
	char& operator[](const int index);
	friend ostream& operator<<(ostream&, const MyString &);
	friend MyString operator+(const char *, const MyString &);

private:
	MyString(const char *, const char *);
	int len;
	char *p;
};

#endif /* MYSTRING_H_ */
/*
 * �Ұ����ϴ��ɻ�����ɣ�����־ְ�¡���ط�
 */
