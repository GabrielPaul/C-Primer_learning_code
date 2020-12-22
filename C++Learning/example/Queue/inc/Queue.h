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

	//1.避免了本来将自动生成的默认方法定义;
	//2.因为方法是私有的,所以不能被广泛使用.
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