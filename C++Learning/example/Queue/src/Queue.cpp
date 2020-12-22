#include"../inc/Queue.h"
#include <cstddef>
Queue::Queue(int qs) :qSize(qs)
{
	front = rear = NULL;
	items = 0;
	//qsize = qs;	//use member initializer list to initialize
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL) 
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isEmpty() const
{
	return items==0;
}

bool Queue::isFull() const
{
	return items ==qSize;
}

int Queue::queueCount() const
{
	return items;
}
bool Queue::enQueue(const Item& item)
{
	if (isFull()) 
	{
		return false;
	}
	Node* add = new Node;
	if (add == NULL)
	{
		return false;
	}
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

bool Queue::deQueue(Item& item)
{
	if (front == NULL) 
	{
		return false;
	}
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0) 
	{
		rear = NULL;
	}
	return true;
}
