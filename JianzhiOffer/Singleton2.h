#ifndef SINGLETON2_H
#define SINGLETON2_H

/*����һ���ֲ���̬�����ﵽ�ӳ�ʵ�������̰߳�ȫ�ĵ���ģʽ*/

#include <iostream>

class Singleton2 {
	Singleton2() { std::cout << "create" << std::endl; }
	Singleton2(const Singleton2&) {}
	Singleton2& operator=(const Singleton2&){}
	~Singleton2() { std::cout << "Destroy" << std::endl; }
	
public:
	static Singleton2* getInstance();
};
#endif
