#ifndef SINGLEYLINKEDLIST_H
#define SINGLEYLINKEDLIST_H

#include "Nodes.h"

TEMPLATED class SingleyLinkedList
{
protected:
	SingleNode<T>* head = nullptr;
	UINT size = 0;

	// Remove all heap allocated elements in list
	void Release();

	// Make a heap allocated copy of all elements
	void DeepCopy(const SingleyLinkedList&);

public:
	// Get/Set Head Node
	SingleNode<T>* GetHeadNode() { return head; }
	void SetHeadNode(SingleNode<T>* node) { head = node; }
	__declspec(property(get = GetHeadNode, put = SetHeadNode)) SingleNode<T>* Head;

	// Get/Set Size
	UINT GetSize() { return size; }
	void SetSize(unsigned int newSize) { size = newSize; }
	__declspec(property(get = GetSize, put = SetSize)) UINT Size;

	// Constructor
	SingleyLinkedList();
	SingleyLinkedList(const T);
	SingleyLinkedList(T*, UINT);

	// Copy Constructor
	SingleyLinkedList(const SingleyLinkedList&);

	// Copy Assignment Operator
	SingleyLinkedList& operator = (const SingleyLinkedList&);

	// Destructor
	virtual ~SingleyLinkedList();

	// Add a new element to the list
	void Add(T);

	// Delete a node specified depth in list
	void Delete(UINT);

	// Print all elements in the list
	void Print();

	// Get the last element of the list
	SingleNode<T>* EndOfList();

	// Get any elment in the list
	SingleNode<T>& operator [] (UINT);

	// Determine if the list is cyclic and where it is
	SingleNode<T>& FindBeginningOfCircle();

	// Find a node of certain depth
	SingleNode<T>* IndexOf(UINT);

	// Output all the elements in the list
	friend std::ostream& operator << (std::ostream& out, SingleyLinkedList& ds) { ds.Print(); return out; }
};

// Empty Constructor
TEMPLATED SingleyLinkedList<T>::SingleyLinkedList() : head(nullptr), size(0) { }

// Constructor with Data
TEMPLATED SingleyLinkedList<T>::SingleyLinkedList(const T data) : size(1)
{
	this->head = new SingleNode<T>(data);
}

// Constructor with array
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
			head = iterator;
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
	return this->IndexOf(this->size);
}

// Add a new element to the end of the list
TEMPLATED void SingleyLinkedList<T>::Add(T data)
{
	EndOfList()->next = new SingleNode<T>(data);
	++size;
}

// Delete an element in the list by
// number depth in the list
// not completed yet
TEMPLATED void SingleyLinkedList<T>::Delete(UINT num)
{
	SingleNode<T>* iterator;
	if (!num)
	{
		// If number is 0 delete head
		iterator = head->next;
		delete head;
		head = iterator;
	}
	else if (num >= this->size)	
	{
		// If number is greater than the size delete last node
		iterator = this->IndexOf(this->size - 2);
		delete iterator->next;
		iterator->next = nullptr;
	}
	else
	{
		// Any number between the head and end of the list
		iterator = this->IndexOf(num);
		this->IndexOf(num - 1)->next = this->IndexOf(num - 1)->next->next;
		delete iterator;
	}

	--this->size;
}

// Access an element in the list by the [] operator
// Ex: list[1] - gets the second element of the list
TEMPLATED SingleNode<T>& SingleyLinkedList<T>::operator [] (UINT index)
{
	return *this->IndexOf(index);
}

TEMPLATED SingleNode<T>* SingleyLinkedList<T>::IndexOf(UINT index)
{
	if (0 <= index && index < size)
	{
		SingleNode<T>* iterator = head;

		for (int i = 0; i < index; ++i)
			iterator = iterator->next;

		return iterator;
	}

	return nullptr;
}

// Print out every element in the list
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

// Finds the first node of a cicular list
TEMPLATED SingleNode<T>& SingleyLinkedList<T>::FindBeginningOfCircle()
{
	SingleNode<T>* slow = this->head;
	SingleNode<T>* fast = this->head;

	// Find meeting point. This will be LOOP_SIZE - k steps into the
	// Linked List
	while (fast != nullptr && fast->next != nullptr)
	{
		if (slow->next != nullptr)
			slow = slow->next;

		if (fast->next->next != nullptr)
			fast = fast->next->next;

		if (slow == fast)
			break;
	}

	// Error check - no meeting point, and therefore no loop
	if (fast == nullptr | fast->next != nullptr)
		return NULL;

	//  Move slow to head. Keep fast at Meeting Point. Each are k
	// steps from the Loop Start. If they move at the same pace,
	// the must meet at loop start
	slow = this->head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	// Both now point to the start of the loop
	return *fast;
}

#endif