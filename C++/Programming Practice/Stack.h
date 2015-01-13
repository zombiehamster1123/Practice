#include "SingleyLinkedList.h"

TEMPLATED class Stack : public SingleyLinkedList<T>
{
public:
	Stack();
	Stack(const T);
	Stack(T*, UINT);
	Stack(const Stack&);
	Stack<T>& operator = (const Stack&);

	void Push(T);
	T Pop();

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
	top = new SingleNode<T>(arrayOfData[0]);

	for (size = 1; size < arraySize; ++i)
		Push(arrayOfData[i]);
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

TEMPLATED void Stack<T>::Push(T data)
{
	SingleNode<T>* item = new SingleNode<T>(data);
	item->next = this->head;
	this->head = item;
	++size;
}

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