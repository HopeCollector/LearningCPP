#include "string.h"
#include <iostream>

void call1(const String &);
void call2(const String );

int main()
{
	{
		using std::endl;
		using std::cout;

		String test1 = "god";
		String test2("nothing");
		String test3("just for test");
		String test4;
		cout << test4;
		// 隐式调用构造函数String(const String &)
		// 如果不是自己定义的函数，编译器将自动生成一个替代品
		call1(test2);
		call2(test3);
		test4 = test3;
		// 调用了赋值运算符=
		// 由c++自动生成的运算符都执行浅复制
	}

	return 0;
}

void call1(const String & s)
{
	std::cout << "call1 \n";
	std::cout << s << std::endl;
}

void call2(const String s)
// 按值传递意味着创造一个原始变量的副本
// 这将会隐式调用复制构造函数
{
	std::cout << "call2\n";
	std::cout << s << std::endl;
}