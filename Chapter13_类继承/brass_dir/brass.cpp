#include <iostream>
#include "brass.h"

using std::endl;
using std::string;

Brass::Brass(const string f_name,
	     const string l_name,
	     unsigned int account,
	     double tl):
  first_name(f_name),
  last_name(l_name),
  id(account),
  total(tl){}			// 使用了初始化成员列表的方法

bool Brass::withdraw(double m)	// virtual关键字只存在于声明之中
{
  bool flag = false;
  if(m <= total)
    {
      total -= m;
      flag = true;
    }
  else
    std::cout << "error : you donot have enough money\n";
  return flag;
}

void Brass::deposit(double m)
{
  total += m;
}

void Brass::showaccount()
{
  std::cout << "name : " << first_name << " " << last_name << endl;
  std::cout << "account : " << id << endl;
  std::cout << "money : " << total << endl;
}

BrassPlus::BrassPlus(double max, double rate, double total,
		     const string f_name, const string l_name, unsigned int account, double tl):
  overdraw_max(max),
  overdraw_rate(rate),
  overdraw_total(total),
  Brass(f_name, l_name, account, tl){} // 初始化基类成员必须要使用初始化成员列表

BrassPlus::BrassPlus(double max, double rate, double total,
	  const Brass & bs):
  overdraw_max(max),
  overdraw_total(total),
  overdraw_rate(rate),
  Brass(bs){}

bool BrassPlus::withdraw(double m)
{
  bool flag = false;
  if(this->Brass::withdraw(m))
    flag = true;
  else
    {
      int owe = m - total;	// 可以使用protected部分的成员
				// 派生类成员可以直接访问这部分的成员，这和public是一样的
				// 但是外部世界无法访问，这和private是一样的
      if(owe < (overdraw_max - overdraw_total))
	overdraw_total += owe;
      flag = true;
    }
  return flag;
}

void BrassPlus::showaccount()
{
  this->Brass::showaccount();
  std::cout << "max_owe : " << overdraw_max << endl;
  std::cout << "rate_owe : " << overdraw_rate << endl;
  std::cout << "total_owe : " << overdraw_total << endl;
}

// void Brass::test()
// {
//   std::cout << "this is Brass\n";
// } 

void BrassPlus::test()
{
  std::cout << "this BrassPlus\n";
}

void BrassPP::test()
{
  std::cout << "this is BrassPP\n";
}
