#include "queue.h"
#include <iostream>

using std::cout;
using std::endl;

QUEUE::Queue::Queue(int node) : max(node)
// 成员初始化列表
// 允许使用这种方法，在程序未进入函数之前将默认值写入常量的内存中
// 类中的私有成员都可以使用这种方式初始化，不限于const常量
{
	// max = node;
	// max是常量，不可以这样初始化
	head = tail = nullptr;
}

QUEUE::Queue::~Queue()
{
	Node *temp;
	while(head != nullptr)
	{
		temp = head->next;
		delete head;	
		head = temp;	
	}
}

bool QUEUE::Queue::is_empty()
{
	return (num_queue == 0);
}

bool QUEUE::Queue::is_full()
{
	return (num_queue == max);
}

bool QUEUE::Queue::enqueue(Cus c)
{
	bool flag = false;
	if(num_queue < max)
	{
		if(head == nullptr)
		{
			head = tail = new Node;
			tail->custome = c;
			tail->next = nullptr;
		}else
		{
			Node* temp;
			temp = new Node;
			temp->custome = c;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
		}
		num_queue++;
		flag = true;
	}
	else
		std::cout << "enqueue error : queue full!\n";
	return flag;
}

bool QUEUE::Queue::dequeue(Cus& c)
{
	bool flag = false;
	if(num_queue > 0)
	{
		Node* temp = head->next;
		c = head->custome;
		delete head;
		head = temp;
		num_queue--;
		flag = true;
	}
	else
		std::cout << "dequeue error : queue is empty\n";
	return flag;
}

int QUEUE::Queue::total()
{
	return num_queue;
}

void Cus::set(long when)
{
	std::srand(std::time(0));
	operate_time = std::rand() % 3 + 1;
	arrive_time = when;
}