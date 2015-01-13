#include "Nodes.h"

TEMPLATED class SingleyLinkedList
{
protected:
	SingleNode<T>* head = nullptr;
	UINT size = 0;

	void Release();
	SingleNode<T>* FindPreviousNode(SingleNode<T>&);
	void DeleteNode(SingleNode<T>&);
	void DeepCopy(const SingleyLinkedList&);

public:
	SingleyLinkedList();
	SingleyLinkedList(const T);
	SingleyLinkedList(T*, UINT);

	SingleyLinkedList(const SingleyLinkedList&);
	SingleyLinkedList& operator = (const SingleyLinkedList&);

	virtual ~SingleyLinkedList();

	SingleNode<T>* GetHeadNode() { return head; }
	void SetHeadNode(SingleNode<T>* node) { head = node; }

	UINT GetSize() { return size; }
	void SetSize(unsigned int newSize) { size = newSize; }

	__declspec(property(get = GetHeadNode, put = SetHeadNode)) SingleNode<T>* Head;
	__declspec(property(get = GetSize, put = SetSize)) UINT Size;

	void Add(T);
	void Delete(UINT);
	void Print();
	SingleNode<T>* EndOfList();
	SingleNode<T>& operator [] (UINT);

	friend std::ostream& operator << (std::ostream& out, SingleyLinkedList& ds) { ds.Print(); return out; }
};

// Empty Constructor
TEMPLATED SingleyLinkedList<T>::SingleyLinkedList() : head(nullptr), size(0) { }

// Constructor with Data
TEMPLATED SingleyLinkedList<T>::SingleyLinkedList(const T data) : size(1)
{
	this->head = new SingleNode<T>(data);
}

TEMPLATED SingleyLinkedList<T>::SingleyLinkedList(T* arrayOfData, UINT arraySize)
{
	head = new SingleNode<T>(arrayOfData[0]);
	SingleNode<T>* iterator = head;

	for (size = 1; size < arraySize; ++size)
	{
		iterator->next = new SingleNode<T>(arrayOfData[size]);
		iterator = iterator->next;
	}
}

// Copy Constructor
TEMPLATED SingleyLinkedList<T>::SingleyLinkedList(const SingleyLinkedList<T>& LinkedListToCopy)
{
	DeepCopy(LinkedListToCopy);
}

// Copy Assignment Operator
TEMPLATED SingleyLinkedList<T>& SingleyLinkedList<T>::operator = (const SingleyLinkedList& LinkedListToCopy)
{
	SingleyLinkedList<T> tmp = SingleyLinkedList<T>(LinkedListToCopy);
	std::swap(head, tmp.head);
	std::swap(size, tmp.size);

	return *this;
}

// Makes a copy of all of the linked lists field in separate heap memory
TEMPLATED void SingleyLinkedList<T>::DeepCopy(const SingleyLinkedList& LinkedListToCopy)
{
	this->Release();

	this->head = new SingleNode<T>(*LinkedListToCopy.head);
	SingleNode<T>* copyIterator = LinkedListToCopy.head->next;
	SingleNode<T>* thisIterator = this->head;

	while (copyIterator != nullptr)
	{
		thisIterator->next = new SingleNode<T>(*copyIterator);
		copyIterator = copyIterator->next;
		thisIterator = thisIterator->next;
	}

	this->size = LinkedListToCopy.size;
}

// Releases all of the heap allocated memory from the list
TEMPLATED void SingleyLinkedList<T>::Release()
{
	if (head != nullptr)
	{
		SingleNode<T>* iterator;

		for (int i = 0; i < size; ++i)
		{
			iterator = head->next;
			delete head;
			head = iterator;//*/
			//DeleteNode(*head);
		}

		head = nullptr;
		size = 0;
	}
}

// Destructor
TEMPLATED SingleyLinkedList<T>::~SingleyLinkedList() { Release(); }

// Goes straight to the last node in the list
TEMPLATED SingleNode<T>* SingleyLinkedList<T>::EndOfList()
{
	SingleNode<T>* iterator = head;

	for (int i = 1; i < size; ++i)
		iterator = iterator->next;

	return iterator;
}

TEMPLATED void SingleyLinkedList<T>::Add(T data)
{
	EndOfList()->next = new SingleNode<T>(data);
	++size;
}

TEMPLATED void SingleyLinkedList<T>::Delete(UINT num)
{
	SingleNode<T>* iterator;
	switch (num)
	{
		case 0..1:
		{
			iterator = head->next;
			delete head;
			head = iterator;
			break;
		}
		case size..INT_MAX:
		{
			break;
		}
		default:
		{
			break;
		}
	}
}

TEMPLATED void SingleyLinkedList<T>::DeleteNode(SingleNode<T>& node)
{
	SingleNode<T>* holder = &node;
	SingleNode<T>* nextHolder = node.next;
	delete holder;
	node = *nextHolder;
}

TEMPLATED SingleNode<T>& SingleyLinkedList<T>::operator [] (UINT index)
{
	if (index < size)
	{
		SingleNode<T>* iterator = head;

		for (int i = 1; i < index; ++i)
			iterator = iterator->next;

		return *iterator;
	}
	
	return NULL;
}

TEMPLATED void SingleyLinkedList<T>::Print()
{
	SingleNode<T>* iterator = head;
	std::cout << "| ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << iterator->storedData << " | ";
		iterator = iterator->next;
	}
}