#ifndef _CUSTOM_H_
#define _CUSTOM_H_
#include <cstdlib>
#include <ctime>

class Cus
{
private:
	int operate_time;
	long arrive_time;

public:
	Cus(){operate_time = arrive_time = 0;}
	void set (long when);
	int need() {return operate_time;}
	long come() {return arrive_time;}
};



#endif