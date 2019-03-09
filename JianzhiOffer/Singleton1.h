#ifndef SINGLETON1_H
#define SINGLETON1_H
/*����ʽ����һ�ε���getInstanceʱ����ʵ��
����˫�ؼ��ͼ���������ȷ���̰߳�ȫ
ע��������������ʵ���ڴ��ͷ�*/

#include <iostream>
#include <mutex>

class Singleton1 {
	Singleton1();
	Singleton1(const Singleton1&){}
	Singleton1& operator=(const Singleton1&){}
	~Singleton1();
	static Singleton1* instance;
	static std::mutex mu;

public:
	static Singleton1* getInstance();
};
#endif
