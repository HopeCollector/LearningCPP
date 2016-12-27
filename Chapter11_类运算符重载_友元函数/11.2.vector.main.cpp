#include "11.1.vector.h"
#include <iostream>

int main()
{
	using namespace std;
	using VECTOR::Vector;

	Vector v1;
	Vector v2 = Vector(10.2, 12.1);
	//和Vector（）的作用是一样的
	Vector v3(15.1, 19.23, Vector::POL);
	//枚举量不能用using命令
	//效果同上，可以省略等号
	Vector v4 = {14, 15, Vector::RECT};
	//允许使用初始化器
	Vector v5 {16, 17, Vector::POL};
	//允许省略等号

	int i;
	v1.test(i);
	cout << "v2 = " << v2 << endl;
	//v2 默认是RECT，这是默认参数的作用
	cout << "v3 + v4 = " << (v1 = v3 + v4) << endl;
	//考虑运算符的优先级
	//运算符重载，允许像使用基本类型一样使用对象
	cout << "-(v3 + v4) = " << -v1 << endl;
	//单目运算符重载，只有原有的运算符拥有单目运算功能，才能重载
	//换句话说，不允许自己创造运算符，但是可以创造运算规则
	cout << "v3 - v4 = " << (v1 = v3 - v4) << endl;
	cout << "v1 in pol " << v1.pol_mode() << endl;
	//this指针返回的的对象就是调用它的对象
	cout << "v1 in RECT" << v1.rect_mode() << endl;
	cout << "v2 * 5 = " << v2 * 5 << endl;
	cout << "5 * v2 = " << 5 * v2 << endl;
	//利用友元函数进行运算符重载
	return 0;
}
//关于注释，//与/**/最好不要混着用，会出现黑魔法