/*
 * bit.cpp
 *
 *  Created on: 2016��1��7��
 *      Author: zhonghuiping
 */

#include "bit.h"

bit::bit() {
	// TODO Auto-generated constructor stub

}
/*
 * s.any()
 * s.none()
 * s.count()
 * s.set()
 * s.reset()
 */
void bit::test()
{
	bitset<16> s(63);
	cout << "��������1�ĸ�����" << s.count() << endl;
	cout << "�����Ƶ�λ����" << s.size() << endl;
	cout << "���е�5λ�ǣ�" << s[5] << endl;
	cout << "�������е�5λ�Ƿ�Ϊ1��" << (s.test(5) ? "Yes" : "NO") << endl;
	cout << "ת���������ǣ�" << s.to_ulong() << endl;
	s.reset(5);
	cout << "�������е�5λ�Ƿ�Ϊ1��" << (s.test(5) ? "Yes" : "NO") << endl;
	cout << "ת���������ǣ�" << s.to_ulong() << endl;
	cout << "ת�����ַ����ǣ�" << s.to_string() << endl;
	cout << "λ����" << s << endl;
}

bit::~bit() {
	// TODO Auto-generated destructor stub
}

