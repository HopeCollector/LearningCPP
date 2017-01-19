#ifndef _ACCTABC_H_
#define _ACCTABC_H_

#include <string>
#include <iostream>

class AcctABC
{
private:
  std::string full_name;
  long id;
  double balance;
protected:
  const std::string & FullName(){return full_name;}
  long Account() {return id;}
  struct formatting
  {
    std::ios_base::fmtflags flag;
    std::streamsize pr;
  };
  formatting SetFormat()const;
  void Restore(formatting & f) const;
public:
  AcctABC (const std::string name = "NULL", long account = -1, double m = 0);
  double Balance(){return balance;}
  void Deposit(double m);
  virtual bool Withdraw(double) = 0; // 纯虚函数，这种情况下允许函数只有声明没有定义
				// 而且这个类只能做抽象类，即不能用这个类定义对象，只能用作基类
  virtual void ShowAccount() const = 0;
  virtual ~AcctABC(){}
};

class Brass : public AcctABC
{
public:
  Brass(const std::string name = "NULL", long account = -1, double m = 0):
    AcctABC(name, account, m) {}
  virtual bool Withdraw(double m);
  virtual void ShowAccount() const;
  virtual ~Brass(){};
};

class BrassPlus : public AcctABC
{
private:
  double owe_rate;
  double owe_balance;
  double owe_max;
public:
  BrassPlus(const std::string name = "NULL", long account = -1, double m = 0,
	    double owe_max = 500, double owe_rate = 0.1115, double owe_balance = 0);
  BrassPlus(const Brass & b,
	    double owe_max = 500, double owe_rate = 0.1115, double owe_balance = 0);
  virtual bool Withdraw(double m);
  virtual void ShowAccount() const;
  void ResetMax(double m = 500) {owe_max = m;}
  void ResetRate(double r = 0.1115) {owe_rate = r;}
  void ResetBalance(double m = 0) {owe_balance = m;}
  virtual ~BrassPlus() {}
};

#endif
