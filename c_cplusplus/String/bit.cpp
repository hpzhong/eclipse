/*
 * bit.cpp
 *
 *  Created on: 2016年1月7日
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
	cout << "二进制中1的个数：" << s.count() << endl;
	cout << "二进制的位数：" << s.size() << endl;
	cout << "其中第5位是：" << s[5] << endl;
	cout << "测试其中第5位是否为1：" << (s.test(5) ? "Yes" : "NO") << endl;
	cout << "转化成整数是：" << s.to_ulong() << endl;
	s.reset(5);
	cout << "测试其中第5位是否为1：" << (s.test(5) ? "Yes" : "NO") << endl;
	cout << "转化成整数是：" << s.to_ulong() << endl;
	cout << "转化成字符串是：" << s.to_string() << endl;
	cout << "位集：" << s << endl;
}

bit::~bit() {
	// TODO Auto-generated destructor stub
}

