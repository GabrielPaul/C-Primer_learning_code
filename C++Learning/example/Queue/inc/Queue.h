#pragma once
#include"../inc/Customer.h"
typedef Customer Item;
class Queue {
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qSize;

	//1.�����˱������Զ����ɵ�Ĭ�Ϸ�������;
	//2.��Ϊ������˽�е�,���Բ��ܱ��㷺ʹ��.
	Queue(const Queue& q) :qSize(0) {}	//peemptive definition
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty()const;
	bool isFull()const;
	int queueCount()const;
	bool enQueue(const Item& item);
	bool deQueue(Item& item);
};