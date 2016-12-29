#include "11.3.convert.h"
#include <iostream>
#include <string>

Snake::Snake()
{
	length = 5;
	name = "no name";
}

Snake::Snake(std::string crt, const int a)
{
	name = crt;
	length = a;
}

Snake::~Snake()
{
}

std::ostream & operator << (std::ostream & os, const Snake & sn)
{
	os << "Snake's name " << sn.name << std::endl;
	os << "Snake's length " << sn.length << std::endl;
	return os;
}

Snake::operator int ()
{
	return length;
}

Snake::operator std::string()
{
	return name;
}

const std::string & Snake::operator = (const std::string &str)
{
	name = str;
	return str;
}