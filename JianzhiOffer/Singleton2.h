//����ʽ2
#ifndef SINGLETON2_H
#define SINGLETON2_H

#include <iostream>
using namespace std;

class Singleton2 {
	Singleton2() { std::cout << "create" << std::endl; }
	Singleton2(const Singleton2&) {}
	Singleton2& operator=(const Singleton2&){}
	~Singleton2() { std::cout << "Destroy" << std::endl; }
	
public:
	static Singleton2* getInstance();
};

#endif  // SINGLETON2_H

//ע���
//1.��Ϊ�ֲ���̬����ֻ�ᱻ��ʼ��һ�Σ��������̰߳�ȫ�ģ�����Ҫ����
//2.getInstance����ָ�����������:������ص������ã�ִ��Singleton2 s21 = Singleton2::getInstance()ʱҪִ��һ�θ��Ƽ�����Singleton2(const Singleton2&)��
//�ⲻ���ϵ���ģʽ���ɸ��Ƶ��ص����������ƹ��캯��������Ϊprivate�����ɷ��ʡ�
//3.���캯��Singleton2()�ھ�̬����static Singleton2 instance��ʼ��ʱ�����ã�����ʼ��һ�Ρ�