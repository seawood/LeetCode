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
//1.��Ϊ�ֲ���̬����ֻ�ᱻ��ʼ��һ�Σ��������̰߳�ȫ�ģ�����Ҫ���������ҿ����еĴ����Ǽ����ģ���
//2.getInstance����ָ����������ã�
