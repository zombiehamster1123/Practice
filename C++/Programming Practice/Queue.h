#ifndef QUEUE_H
#define QUEUE_H

#include "SingleyLinkedList.h"

TEMPLATED class Queue : public SingleyLinkedList <T>
{
	Queue();
	Queue(const T);
	Queue(T*, UINT);
	Queue(const Queue&);
	Queue<T>& operator = (const Queue&);

	T Pop_Front();

	friend std::ostream& operator << (std::ostream& out, Queue& que) { que.Print(); return out; }
};

TEMPLATED Queue<T>::Queue() : head(nullptr), size(0) { }

TEMPLATED Queue<T>::Queue(const T data)
{
	this->size = 1;
	this->head = new SingleNode<T>(data);
}

TEMPLATED Queue<T>::Queue(T* arrayOfData, UINT arraySize)
{
	if (arrayOfData != nullptr)
	{
		this->head = new SingleNode<T>(arrayOfData[0]);

		for (this->size = 1; this->size < arraySize; ++this->size)
			this->Add(arrayOfData[this->size]);
	}
}

TEMPLATED Queue<T>::Queue(const Queue<T>& queueToCopy)
{
	DeepCopy(queueToCopy);
}

TEMPLATED Queue<T>& Queue<T>::operator = (const Queue<T>& queueToCopy)
{
	Queue<T> tmp = Queue<T>(queueToCopy);
	std::swap(temp.top);
	std::swap(temp.size);

	return *this;
}

TEMPLATED Queue<T>::~Queue()
{
	this->Release();
}

TEMPLATED T Queue<T>::Pop_Front()
{
	if (head != nullptr)
	{
		T data = head->storedData;
		SingleNode<T>* holder = head->next;
		delete head;
		head = holder;
		--size;

		return data;
	}

	return NULL;
}

#endif