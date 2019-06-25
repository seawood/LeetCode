//����ʽ1
#ifndef SINGLETON1_H
#define SINGLETON1_H

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

//ע���
//1.���캯���͸�ֵ�����������Ϊprivate����ֹ���ⲿ����ʵ����
//2.�������������ͷ��ڴ�
//3.�̰߳�ȫ��������˫�ؼ�飨��һ�μ����Ϊ��Ч�ʣ�ֻ����instanceΪnullptrʱ�ų��Ի�ȡ����
//�ڶ��μ������Ϊ�ڵ�һ�μ�鵽��ȡ���ڼ䣬ʵ���п����Ѿ�������̴߳����ˣ����Ҫ�ټ��һ�Σ�
//4.����ʽ���ڵ�һ�ε���getInstanceʱ����ʵ��