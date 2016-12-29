#include "string.h"
#include <iostream>

int main()
{
	{
		using namespace std;
		const int SIZE = 512;
		char* buffer = new char [SIZE];

		String test1("heap1");
		String* test2 = new (buffer) String ("use buffer test2");
		String* test3 = new (buffer + sizeof(String)) String ("use buffer test3");

		cout << "heap address : 0x" << &test1 << endl;
		cout << "buffer address : 0x" << (void*)buffer << endl;

		cout << "now delete test*!\n";
		test3->~String();
		// 析构变量的顺序遵守栈的规则，先入后出
		// 因为后创建的变量是依附于先创建的变量的
		test2->~String();
		// 使用定位new创建的String变量是不能用
		// delete test2 这类语句删除的
		// 因为定位new与delete是不匹配的
	}
	std::cin.get();
	return 0;
}