#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "queue_custom.h"

namespace QUEUE
{
	struct Node
	{
		Cus custome;
		Node* next;
	};

	class Queue
	{
	private:
		static const int MAX = 10;
		const int max ;
		int num_queue = 0;
		// 内初始化
		// 调用构造函数将覆盖这个值
		// 允许初始化一切类成员，静态类成员除外，这种东西单独存储，多个类仅共享一个
		Node* head;
		Node* tail;

	public:
		Queue(int node = MAX);
		~Queue();
		bool is_empty();
		bool is_full();
		bool enqueue(Cus);
		bool dequeue(Cus&);
		int total();

	};
}
	
#endif