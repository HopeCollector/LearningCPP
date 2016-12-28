#include "string.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	const int NUM = 10;

	String saying[NUM];
	int max = 0;
	int min = 0;

	cout << "Enter saying per line\n";
	for(int i = 1; cin && (i < NUM); i++)
	{
		cout << i << ": ";
		cin >> saying[i - 1];
	}
	if(!cin)
	{
		cin.clear();
		cin.get();
	}

	for(int i = 0; saying[i].Length(); i++)
	{
		cout << "here are what you entered\n";
		cout << saying[i] << endl;
	}
	cout << "change the first saying's first word from"
	<< saying[0][0] << " to " << "r\n";
	saying[0][0] = 'r';
	cout << "Done!\n";
	cout << saying[0];

	for (int i = 0; saying[i].Length(); i++)
	{
		if(saying[max] < saying[i])
			max = i;
		if(saying[min] > saying [i])
			min = i;
	}

	cout << "here is the longest saying you entred\n";
	cout << saying[max] << endl;
	cout << "here is the shortest saying you entered\n";
	cout << saying[min] << endl;

	cin.get();
	return 0;
}