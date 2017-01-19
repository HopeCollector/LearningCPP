#include "brass.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Brass test1("jone", "simth", 123456, 1530.4);
  Brass test2("helen", "tom", 234567, 3402.9);
  BrassPlus ptest1(500,0.11125,0,"vip", "mr", 111111, 120012.5); // 传入实际值的参数左面的参数必须都使用实际参数

  cout << "three user\n";
  test1.showaccount();
  test2.showaccount();
  ptest1.showaccount();

  cout << "take 1000 from jone\n";
  test1.withdraw(1000);
  test1.showaccount();

  cout << "take 5000 from helen, but she doesn't have enough money\n";
  test2.withdraw(5000);
  test2.showaccount();

  cout << "take all money from vip\n";
  ptest1.withdraw(120012.5);
  ptest1.showaccount();
  cout << "borrown 300 from bank\n";
  ptest1.withdraw(300);
  ptest1.showaccount();
  cout << "borrow 300 from bank\n";
  if(ptest1.withdraw(300))
    cout << "that's impossible\n";
  else
    cout << "you can't do that\n";
  ptest1.showaccount();

  cout << "miss helen is a vip now\n";
  BrassPlus ptest2(1000, 0.01, 0, test2);
  ptest2.showaccount();

  cout << "test for virtual\n";
  BrassPlus v1(500, 0.1, 0, "Brass", "1", 123456, 1000);
  Brass * BPp = &v1;
  Brass & BPc = v1;
  // BrassPlus is a Brass, 这种关系是不可逆的，也就是说指针在不使用强制类型转换的情况下由基类指向派生类
  cout << "test for pointer\n";
  cout << "BPp->v2\n";
  cout << "took 1200 from v2\n";
  BPp->withdraw(1200);		// 编译器将在程序运行时选择正确的方法，这种在执行过这种确定运行代码块的
				// 方法，被称为动态联编
				// 在编译时就决定使用哪个函数的方法叫静态联编
  BPp->showaccount();
  cout << endl << endl;

  v1 = BrassPlus(500, 0.1, 0, "Brass", "1", 123456, 1000);
  
  cout << "test for quote\n";
  cout << "BPc = v1\n";
  BPc.withdraw(1200);
  BPc.showaccount();
  cout << endl << endl;

  cout << "\ntest virtual\n";
  BrassPP bpp;
  BrassPlus bp;
  // Brass b;
  // Brass & p1 = b;
  BrassPlus & p2 = bp;
  BrassPlus & p3 = bpp;

  // cout << "this is p1 = b\n";
  // p1.test();
  cout << "this is p2 = bp\n";
  p2.test();
  cout << "this is p3 = bpp\n";
  p3.test();
  
  return 0;
}
