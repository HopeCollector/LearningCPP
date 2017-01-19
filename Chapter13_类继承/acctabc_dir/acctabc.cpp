#include "acctabc.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//****AcctABC****
AcctABC::formatting AcctABC::SetFormat() const // const关键字不只存在于声明
{
  AcctABC::formatting f;
  f.flag = cout.setf(std::ios_base::fixed,
		     std::ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}

void AcctABC::Restore(AcctABC::formatting & f)const
{
  cout.setf(f.flag, std::ios_base::floatfield);
  cout.precision(f.pr);
}

AcctABC::AcctABC(const std::string name, long account, double m):
  full_name(name), id(account), balance(m){}

void AcctABC::Deposit(double m)
{
  if(m < 0)
    cout << "error : you cann't deposit negetive money from bank\n";
  else
    balance += m;
}

bool AcctABC::Withdraw(double m)
{
  bool flag = false;
  if(m > this->AcctABC::Balance())
    cout << full_name << " doesn't have enough money\n";
  else
    {
      balance -= m;
      flag = true;
    }
  return flag;
}

void AcctABC::ShowAccount() const
{
  formatting f = SetFormat();
  cout << "   name : " << full_name << endl;
  cout << "     id : " << id << endl;
  cout << "balance : " << balance << endl;
  Restore(f);
}

//****Brass****
bool Brass::Withdraw(double m)
{
  return AcctABC::Withdraw(m);
}

void Brass::ShowAccount() const
{
  AcctABC::ShowAccount();
}

//****BrassPlus****
BrassPlus::BrassPlus(const string name, long account, double m,
		     double max, double rate, double balance):
  AcctABC::AcctABC(name, account, m),
  owe_max(max),
  owe_rate(rate),
  owe_balance(balance) {}

BrassPlus::BrassPlus(const Brass & b,
		     double max, double rate, double balance):
  AcctABC::AcctABC(b)
{
  owe_max = max;
  owe_rate = rate;
  owe_balance = balance;
}

bool BrassPlus::Withdraw(double m)
{
  bool flag = true;
  
  if(m <= this->AcctABC::Balance())
    return AcctABC::Withdraw(m);
  else
    {
      double owe = m - this->AcctABC::Balance();
      if(owe < (owe_max - owe_balance))
	{
	  AcctABC::Withdraw(m - owe);
	  owe_balance += owe;
	}
      else
	{
	  cout << this->FullName() << " can't borrow more money from bank\n";
	  flag = false;
	}
    }
  return flag;
}

void BrassPlus::ShowAccount() const
{
  AcctABC::ShowAccount();
  AcctABC::formatting f = AcctABC::SetFormat();
  cout << "rate : " << owe_rate << endl;
  cout << "max : " << owe_max << endl;
  cout << "owe balance : " << owe_balance << endl;
  AcctABC::Restore(f);
}
