#include "string.h"
#include <iostream>

using std::cout;
using std::cin;


int String::num_string = 0;
// 初始化静态类成员为0
// 语句指出了以下几点
// 类型 作用域 初始值（没指出staic关键字）
// 静态类成员是单独存储的，初始化放在类声明外面
// 如果静态类成员有关键字const或者是枚举类型，则可以在类声明中初始化
// 一般情况下把初始化放在类方法实现中，要是放在类声明中可能出现重复定义

void String::strcpy(const char* src, char* dst)
{
	int i;
	for(i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';
}

int String::strlen(const char* str)
{
	int i;
	for(i = 0; str[i]; i++);
	return i + 1;
}

String::String(const char* ctr)
{
	num_string ++;
	iLength = strlen(ctr);
	name = new  char [iLength +1];
	strcpy(ctr, name);
	// cout << name << " created\n";//debug
}

String::String(const String & s)
{
	num_string++;
	iLength = s.iLength;
	name = new char [iLength + 1];
	strcpy(s.name, name);
}

String::String()
{
	iLength = 0;
	name = new char[1];
	strcpy("\0", name);
	num_string++;
}

String::~String()
{
	num_string--;
	// cout << name << "deleted\n";//debug
	delete [] name;
	// new和delete的类型一定要匹配（这不是废话么）
}

char& String::operator [] (const int i)
{
	return name[i];
}

char& String::operator [] (const int i)const
{
	return name[i];
}

String & String::operator = (const String &s)
{
	if(this == &s)
		return *this;
	iLength = s.iLength;
	delete [] name;
	name =  new char [iLength + 1];
	strcpy(s.name, name);
	// 深度复制，将复制指针指向位置的内容
	// c++自动创建的函数默认执行浅复制
	// 浅复制，单纯的复制指针
	return *this;
}

String& String::operator = (const char * ctr)
{
	delete [] name;
	iLength = strlen(ctr);
	name = new char[iLength + 1];
	strcpy(ctr, name);
	return *this;
}

bool operator > (const String & s1, const String & s2)
{
	return (std::strcmp(s1.name, s2.name) > 0);
}

bool operator < (const String & s1, const String & s2)
{
	return (std::strcmp(s1.name, s2.name) < 0);
}

bool operator == (const String & s1, const String & s2)
{
	bool flag = (std::strcmp(s1.name, s2.name) == 0);
	return flag;
}

std::ostream & operator << (std::ostream & os, const String & s)
{
	os << s.name;
	return os;
}

std::istream & operator >> (std::istream & is, String & s)
{
	char temp [String::CINLIM];
	is.get(temp, String::CINLIM);
	// 这是一个套路，记好了
	if(is)
		s = temp;
	while(is && (is.get() != '\n'));
// is的作用和if（is）一样，如果is读取到错误的东西，或者is读取了一个空行
// 则is的值会被设置为false
	return is;
}