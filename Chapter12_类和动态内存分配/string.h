#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class String
{
private:
	static const int CINLIM = 80;
	char* name;
	int iLength;
	static int num_string;
	//无论创建多少个对象，静态类成员始终只有一个
	void strcpy(const char *, char*);
	int strlen(const char*);

public:
	String(const char*);
	// 带参数的构造函数也可以是默认构造函数，只要参数有默认值
	String(const String &);
	// 如果类中包含了使用new初始化的指针成员，应该定义一个复制构造函数
	String();
	~String();
	
	int Length(){return iLength;}
	char & operator [] (const int);
	// 可以实现这种功能 test1[0] = 'r'
	char & operator [] (const int)const;
	// 这个函数是针对 const String 这样的声明的
	String & operator = (const String &);
	// 将已有的对象复制给另一个对象时,将使用重载的赋值运算符
	String & operator = (const char*);
	// 对于需要深度复制的类，定义一个赋值运算符是非常有必要的
	friend bool operator > (const String & , const String &);
	friend bool operator < (const String & , const String &);
	friend bool operator == (const String & , const String &);
	// 如果不使用友元函数，形如
	// "heheda" > test1; 这样的代码是过不了编译的
	friend std::ostream & operator << (std::ostream&, const String &);
	friend std::istream & operator >> (std::istream&, String &);
};

#endif