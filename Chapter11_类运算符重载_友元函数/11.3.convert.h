#ifndef _CONVERT_H_
#define _CONVERT_H_
#include <iostream>
#include <string>

class Snake
{
private:
	int length;
	std::string name;

public:
	Snake();
	Snake(std::string ,const int a = 5);
	~Snake();
	int bodylength(){ return length;}
	void grow() { length++; }
	operator int ();
	// 隐式转换函数,也可以显示调用
	explicit operator std::string ();
	// 要求显示使用转换函数
	const std::string & operator = (const std::string &);

	friend std::ostream & operator << (std::ostream &, const Snake &);
	// 如果不返回引用
	// 编译都过不了，cout，cin，cerr这样的对象不能按值传递
};
#endif