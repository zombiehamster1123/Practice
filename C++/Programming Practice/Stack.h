#ifndef STACK_H
#define STACK_H

#include "SingleyLinkedList.h"

TEMPLATED class Stack : public SingleyLinkedList<T>
{
public:
	Stack();
	Stack(const T);
	Stack(T*, UINT);
	Stack(const Stack&);
	Stack<T>& operator = (const Stack&);
	~Stack();

	void Push(T);
	T Pop();
	T Peek();

	friend std::ostream& operator << (std::ostream& out, Stack& st) { st.Print(); return out; }
};

TEMPLATED Stack<T>::Stack() : head(nullptr), size(0) { }

TEMPLATED Stack<T>::Stack(const T data)
{
	this->size = 1;
	this->head = new SingleNode<T>(data);
}

TEMPLATED Stack<T>::Stack(T* arrayOfData, UINT arraySize)
{
	if (arrayOfData != nullptr)
	{
		this->head = new SingleNode<T>(arrayOfData[0]);

		for (this->size = 1; this->size < arraySize; ++this->size)
			Push(arrayOfData[this->size]);
	}
}

TEMPLATED Stack<T>::Stack(const Stack<T>& stackToCopy)
{
	DeepCopy(stackToCopy);
}

TEMPLATED Stack<T>& Stack<T>::operator = (const Stack<T>& stackToCopy)
{
	Stack<T> tmp = Stack<T>(stackToCopy);
	std::swap(temp.top);
	std::swap(temp.size);

	return *this;
}

TEMPLATED Stack<T>::~Stack()
{
	this->Release();
}

TEMPLATED void Stack<T>::Push(T data)
{
	SingleNode<T>* item = new SingleNode<T>(data);
	item->next = this->head;
	this->head = item;
	++size;
}

// Remove the last element put onto the stack
TEMPLATED T Stack<T>::Pop()
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

// Return the top most element on the stack
TEMPLATED T Stack<T>::Peek()
{
	if (this->head != nullptr)
		return this->head->storedData;

	return NULL;
}

#endif