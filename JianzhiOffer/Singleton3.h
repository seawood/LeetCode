//����ģʽ

#ifndef SINGLETON3_H
#define SINGLETON3_H

#include <iostream>
using namespace std;

class Singleton3 {
	Singleton3() { cout << "create" << endl; }
	Singleton3(const Singleton3& s){}
	Singleton3& operator=(const Singleton3 &s){}
	~Singleton3();
	static Singleton3* instance;
public:
	static Singleton3* getInstance();
};

#endif  // SINGLETON3_H

//ע���
//1.����ģʽ������ؽ�����ʵ����
//2.��Ϊ�����ʱ�ͳ�ʼ�����������̰߳�ȫ����
//3.��Ȼ��̬�����ڳ������ʱ�ɳ����Զ����٣�����instanceָ����ڴ�Ҫ�������������ֶ�delete
