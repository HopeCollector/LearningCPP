#include <iostream>
#include "acctabc.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  AcctABC * ap[2];
  int temp;
  
  for(int i = 0; i < 2; i++)
    {
      cout << "Choose account type\n";
      cout << "1 Brass\n" << "2 BrassPlus\n";
      cin >> temp;
      switch(temp)
	{
	case 1:
	  ap[i] = new Brass ("brass", 123456 + i, 1000);
	  break;
	case 2:
	  ap[i] = new BrassPlus("brassplus", 234567 + i, 1000);
	  break;
	}
    }
  
  cout << "take 1200 from ap[0]\n";
  ap[0]->Withdraw(1200);
  ap[0]->ShowAccount();
  cout << endl;

  cout << "take 1200 from ap[1]\n";
  ap[1]->Withdraw(1200);
  ap[1]->ShowAccount();
  cout << endl;

  for(int i = 0; i < 2; i++)
    delete ap[i];

  return 0;
  
}
