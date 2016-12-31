#include "queue.h"
#include <iostream>

int main()
{
	{
		using std::endl;
		using std::cout;
		
		QUEUE::Queue test;
		cout << "test empty? " << test.is_empty();
		cout << endl;
		cout << "add four cus !\n";
		for(int i = 0; i < 4; i++)
			test.enqueue(i);
		cout << "test empty? " << test.is_empty();
		cout << endl;
		cout << "test full? " << test.is_full();
		cout << endl;

		QUEUE::Queue test2(15);
		cout << "now we have a bigger queue\n";
		for(int i = 0; i < 15; i++)
			test2.enqueue(i);
		cout << "test2 full? " << test2.is_full();
		cout << endl;
		test2.dequeue();
		cout << "now? " << test2.is_full();
		cout << endl;
	}
	std::cin.get();
	return 0;
}