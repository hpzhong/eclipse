/*
 * vec.cpp
 *
 *  Created on: 2016年1月7日
 *      Author: zhonghuiping
 */

#include "vec.h"

vec::vec()
{
	// TODO Auto-generated constructor stub

}

vec::~vec()
{
	// TODO Auto-generated destructor stub
}
void vec::sample()
{
	vector<int> ss(10, 3);
	cout << ss.size() << endl;
	cout << ss.empty() << endl;
	ss.push_back(30);

	cout << "##########################" << endl;
	for (vector<int>::size_type i = 0; i < ss.size(); i++) {
		cout << ss[i] << " ";
	}
	cout << endl;

	cout << "##########################" << endl;
	for (vector<int>::iterator iter = ss.begin(); iter < ss.end(); iter++) {
		*iter = 1;
	}
	cout << endl;

	cout << "##########################" << endl;
	for (vector<int>::const_iterator iter = ss.begin(); iter < ss.end();
			iter++) {
		cout << *iter << " ";
	}
	cout << endl;

}
void vec::input()
{
	//String
	vector<string> str;
	string word;
	while (cin >> word) {
		str.push_back(word);
		if (word == "end")
			break;
	}
	for (vector<string>::size_type i = 0; i < str.size(); i++) {
		cout << str[i] << endl;
	}
}
void vec::test()
{
	vector<int> s(5);
	cout << "##########################" << endl;
	for (vector<int>::const_iterator iter = s.begin(); iter < s.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

}
