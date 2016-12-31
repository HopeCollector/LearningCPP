#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int hour_min = 60;

bool newcome(int);

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::rand;
	using std::srand;
	using std::time;
	using std::ios_base;
	using QUEUE::Queue;

	int max;
	int average_cus;
	int hour;
	int whole_time;
	int wait_time = 0;
	int total_cus = 0;
	int total_reject = 0;
	int total_served = 0;
	long total_wait_time = 0;
	long total_queue_length = 0;

	cout << "set max queue : ";
	cin >> max;
	cin.get();
	cout << "set average_cus per hour : ";
	cin >> average_cus;
	cin.get();
	cout << "set seve hour : ";
	cin >> hour;
	cin.get();

	Queue queue(max);

	srand(time(0));
	whole_time = hour * hour_min;

	for(long i = 0; i < whole_time; i++)
	 {
 		total_queue_length += queue.total();
	 	if(newcome(average_cus))
	 	{
	 		total_cus++;
	 		Cus custome;
	 		custome.set(i);
	 		if(!queue.is_full())
	 		{
	 			queue.enqueue(custome);
	 		}else
	 			total_reject++;
	 	}
	 	if(wait_time == 0)
 		{
 			if(!queue.is_empty())
 			{
 				Cus temp;
 				queue.dequeue(temp);
 				wait_time = temp.need();
 				total_wait_time += i - temp.come();
 				total_served++;
 			}
 		}else
 			wait_time--;
	 }

	 cout << "total customers : " << total_cus << endl;
	 cout << "total servered customers : " << total_served << endl;
	 cout << "total reject customers : " << total_reject << endl;
	 cout.precision(2);
	 cout.setf(ios_base::fixed, ios_base::floatfield);
	 cout << "average wite time : " << (double)total_wait_time / total_served * 1.0 << endl;
	 cout << "average queue total_queue_length : " << (double)total_queue_length / whole_time << endl;
	 cin.get();

	return 0;
}

bool newcome(int average_cus)
{
	return (rand() * average_cus / RAND_MAX);
}