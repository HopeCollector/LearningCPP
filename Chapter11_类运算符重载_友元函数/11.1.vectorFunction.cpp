#include <iostream>
#include <cmath>
#include "11.1.Vector.h"

using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::sqrt;
using std::endl;

namespace VECTOR
{
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		ang = atan2(y, x) * 45 / atan(1);
		//c++内置的数学函数使用的是弧度制，必须转换
	}

    Vector::Vector()
    {
    	x = y = mag = ang =0;
    	mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)//不要再函数定义里设置默认参数
    {
    	switch(form)
		{
			case RECT:
			x = n1;
			y = n2;
			set_mag();
			set_ang();
			break;

			case POL:
			mag = n1;
			ang = n2;
			set_x();
			set_y();
			break;

			default:
			std::cout << "Vector error : wrong mode!!\n";
			Vector();
			
		}
		mode = form;
    }

    Vector::~Vector()
    {}

    void Vector::reset()
    {
    	x = y = mag = ang = 0;
    	mode = RECT;
    }

    Vector Vector::operator + (const Vector & a)const
    {
    	return Vector(x + a.x, y + a.y);
    }

    Vector Vector::operator - (const Vector & a)const
    {
    	return Vector(x - a.x, y - a.y);
    }

    Vector Vector::operator - ()const
    {
    	return Vector(-x, -y);
    }

    //template <typename T>
    Vector Vector::operator * (const int & a)const
    {
    	return Vector(a * x, a * y);
    }

    //template <typename T>
    Vector operator * (const int & a, const Vector & b)
    //友元函数的定义不需要friend，正常定义就可以
    {
    	return b * a;
    }

    std::ostream & operator << (std::ostream & os, const Vector & b)
    //重载<<
    {
    	switch(b.mode)
		{
			case Vector::RECT:
			os << "(x, y) = " << b.x << ", "<< b.y << endl;
			break;

			case Vector::POL:
			os << "(mag, ang) = " << b.mag << ", " << b.ang << endl;
			break;
			
			default:
			cout << "operator error : wrong mode\n";

		}
		return os;
    }

}