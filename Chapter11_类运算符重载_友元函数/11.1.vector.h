#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

namespace VECTOR
{
  class Vector
  {
  public:
  	enum Mode {RECT, POL};//只有声明成公有的才能在类以外使用

  private:
    double x, y;
    double mag, ang;
    Mode mode;
    void set_x();
    void set_y();
    void set_mag();
    void set_ang();
    
  public:
    Vector();
    Vector(double, double, Mode form = RECT);
    //默认参数一定要设置在函数声明中，设置在定义里没用
    ~Vector();
    double xval() {return x;}
    //这种函数是内联函数
    double yval() {return y;}
    double magval() {return mag;}
    double angval() {return ang;}
    Vector rect_mode();
    Vector pol_mode();
    void reset();
    template <typename T>
	void test(T a);
    //运算符重载
    //语法：
    //operator <运算符> (参数);
    Vector operator + (const Vector &)const;
    //外面这个const表示调用成员函数的对象不会被改变
    Vector operator - (const Vector &)const;
    Vector operator - () const;

    //template <typename T>
    Vector operator * (const int &)const;

    //template <typename T>
    friend Vector operator * (const int &, const Vector &);
	//使用了函数模板
	//函数模板的语法必须同时应用在函数声明与定义上
	//函数模板不支持分离编译，声明与实现必须放在一起
	//具体的还有点懵圈，等看到之后再回来写
    //这是友元函数
    //这种函数的原型在类中，但是并不是成员函数（这种函数没办法被调用）
    friend std::ostream & operator << (std::ostream &, const Vector &);
  };
  //内联函数，要求定义存在于每一个调用他的文件里
  //一个可行的解决办法是，把定义放在头文件里
  //普通的内联函数要求inline关键字同时存在于函数原型和函数定义中
  //类成员只需要把inline关键字放在函数定义中就可以
  inline Vector Vector::rect_mode()
    {
    	mode = RECT;
    	return *this;
    	//this指针，默认指向调用他的对象
    	//这个指针是隐式声明的
    }

    inline Vector Vector::pol_mode()
    {
    	mode = POL;
    	return *this;
    }

    template <typename T>
    void test(T a){}
}


#endif