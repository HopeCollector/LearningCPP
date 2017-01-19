#include <string>

class Brass
{
protected:
  double total;
 private:
  std::string first_name;
  std::string last_name;
  int id;

 public:
  Brass(const std::string f_name = "none",
	const std::string l_name = "none",
	unsigned int account = 0,
	double tl = 0);
  virtual  bool withdraw (double);
  void deposit (double);
  double total_left() {return total;}
  virtual void showaccount();	// 虚方法，改变对象选择方法的方法
				// 改变之前方法的选择按照指针的类型或者，引用的类型选择方法
				// 加上关键字之后按照原对象的类型选择方法
  virtual ~Brass() {}		// 虚析构函数使得BrassPlus对象可以使用相应的析构函数，而不是Brass的
  // void test();
};

class BrassPlus : public Brass /* 派生类不能直接访问基类的成员，只能通过公共声明的函数访问 */
// 被继承类声明成 public 才能实现
// BrassPlus v1(500, 0.1, 0, "Brass", "1", 123456, 1000);
// Brass * BPp = &v1;
{
 private:
  double overdraw_max;
  double overdraw_rate;
  double overdraw_total;

 public:
  BrassPlus(double max = 500,
	    double rate = 0.11125,
	    double total = 0,
	    const std::string f_name = "none",
	    const std::string l_name = "none",
	    unsigned int account = 0,
	    double tl = 0);
  BrassPlus(double max,
	    double rate,
	    double total,
	    const Brass & bs); 	/* 血的教训，设置默认值的参数后面的所有参数都必须设置默认值 */
  double total_owe() {return overdraw_total;}
  double max_owe() {return overdraw_max;}
  virtual bool withdraw(double); // 一般来说，在派生类中重定义的方法都会被声明为虚方法
  virtual void showaccount();
  virtual void test();
};

class BrassPP : public BrassPlus
{
 public:
  void test();
};
