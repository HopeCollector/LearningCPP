#include "11.3.convert.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	Snake test1;
	Snake test2 = {"heheda", 10};

	cout << test1 << endl;
	test1.grow();
	cout << "After grow\n";
	cout << test1;
	cout << "\n\n";
	cout << "test2\n";
	cout << test2;
	//test2 = 15;
	//这相当与调用Snake（const int）
	// 这个函数会创造一个新的临时对象
	// 这就使得name是乱码
	// 对Snake来说，隐式转换是用不了的
	// 因为name的内存无法释放
	//cout << "After test = 15\n";
	//cout << test2;
	string a = string(test2);
	// 本来可以隐式转换的,但是加上了explicit关键字,只能显示调用了
	test1 = a;
	cout << "change test1's name to test2's name \n";
	cout << test1;
	cin.get();

	return (int)0;
}