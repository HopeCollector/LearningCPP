#include "11.1.vector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>//用来进行文件输入

int main()
{
	using namespace VECTOR;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::srand;
	using std::time;
	using std::rand;
	using std::ofstream;

	int step_length;//%运算符的第二个操作数必须是整形变
	double target;
	int count = 0;
	Vector point;

	srand(time(0));
/*	cout << "Enter your goal\n";
	cin >> target;
	cout << "Enter your step length\n";
	cin >> step_length;

	while(point.magval() < target)
	{
		count ++;
		point = point + Vector(step_length, rand() % 360, Vector::POL);
	}

	cout << "total " << count << " steps\n";
	cout << "average step " << target / count << endl;
	cout << "done! \n";

	cin.get();
	cin.get();*/
	//上面的程序是一次性的

	/*
	cout << "Enter your target\n";
	while(cin >> target)
	{
		cout << "Enter your step length\n";
		if(!(cin >> step_length))
		{
			cout << "cin error: wrong step!\n";
			break;
		}
		while(point.magval() < target)
		{
			count++;
			point = point + Vector(step_length, rand() % 360, Vector::POL);
		}
		cout << "Total steps : " << count << endl;
		cout << "Averge step length : " << target * 1.0 / count << endl;
		cout << "Enter your target\n";
		count = 0;
		point.reset();
	}
	cin.clear();
	*/
	//上面的程序是重复的

	ofstream fout;
	const int num = 1000;
	long double whole_step = 0;

	fout.open("test.txt");
	//类似于c的套路，先将fout与文件关联起来
	cout << "Enter your target\n";
	cin >> target;
	cout << "Enter your step length\n";
	if(!(cin >> step_length))
	{
		cout << "cin error: wrong step!\n";
		return 0;
	}
	for(int i = 0; i < num ; i++)
	{
		while(point.magval() < target)
		{
			count++;
			point = point + Vector(step_length, rand() % 360, Vector::POL);
		}
		fout << "Total steps : " << count;
		//输入输出的方法和cout是一样的，這使用了运算符重载
		fout << "    Averge step length : " << target * 1.0 / count << endl;

		whole_step += (target * 1.0 / count);
		count = 0;
		point.reset();
	}

	fout << "average steps : " << target * num / whole_step;

	fout.close();
	//这里使用了文件输入
	cin.clear();
	return 0;
}