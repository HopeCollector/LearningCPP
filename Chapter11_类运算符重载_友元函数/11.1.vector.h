#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

namespace VECTOR
{
  class Vector
  {
  public:
  	enum Mode {RECT, POL};//ֻ�������ɹ��еĲ�����������ʹ��

  private:
    double x, y;
    double mag, ang;
    Mode mode;
    void set_x();
    void set_y();
    void set_mag();
    void set_ang();
    
  public:
    Vector();
    Vector(double, double, Mode form = RECT);
    //Ĭ�ϲ���һ��Ҫ�����ں��������У������ڶ�����û��
    ~Vector();
    double xval() {return x;}
    //���ֺ�������������
    double yval() {return y;}
    double magval() {return mag;}
    double angval() {return ang;}
    Vector rect_mode();
    Vector pol_mode();
    void reset();
    template <typename T>
	void test(T a);
    //���������
    //�﷨��
    //operator <�����> (����);
    Vector operator + (const Vector &)const;
    //�������const��ʾ���ó�Ա�����Ķ��󲻻ᱻ�ı�
    Vector operator - (const Vector &)const;
    Vector operator - () const;

    //template <typename T>
    Vector operator * (const int &)const;

    //template <typename T>
    friend Vector operator * (const int &, const Vector &);
	//ʹ���˺���ģ��
	//����ģ����﷨����ͬʱӦ���ں��������붨����
	//����ģ�岻֧�ַ�����룬������ʵ�ֱ������һ��
	//����Ļ��е���Ȧ���ȿ���֮���ٻ���д
    //������Ԫ����
    //���ֺ�����ԭ�������У����ǲ����ǳ�Ա���������ֺ���û�취�����ã�
    friend std::ostream & operator << (std::ostream &, const Vector &);
  };
  //����������Ҫ���������ÿһ�����������ļ���
  //һ�����еĽ���취�ǣ��Ѷ������ͷ�ļ���
  //��ͨ����������Ҫ��inline�ؼ���ͬʱ�����ں���ԭ�ͺͺ���������
  //���Աֻ��Ҫ��inline�ؼ��ַ��ں��������оͿ���
  inline Vector Vector::rect_mode()
    {
    	mode = RECT;
    	return *this;
    	//thisָ�룬Ĭ��ָ��������Ķ���
    	//���ָ������ʽ������
    }

    inline Vector Vector::pol_mode()
    {
    	mode = POL;
    	return *this;
    }

    template <typename T>
    void test(T a){}
}


#endif