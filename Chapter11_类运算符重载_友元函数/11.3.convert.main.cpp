#include "11.3.convert.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	Snake a("baba", 15);
	Snake b("daughter", 9);
	cout << a;
	cout << b;

	cout << "get a's name by string ";
	string name_a = string(a);
	cout << name_a << endl;
	cout << "get b's length by int ";
	int length_b = b;
	cout << length_b << endl;
	cin.get();
	return 0;
}