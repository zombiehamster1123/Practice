#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Nodes.h"
#define TABLE_SIZE 10

HASH_TEMPLATE
class HashTable
{
private:
	Hash<T, N>* head = nullptr;
	int size = 0;

	void Create();
	void DeepCopy(const HashTable<T, N>& otherTable);
	void Release();
	void Print();
	Hash<T, N>* LastNodeInHash(const int);

public:
	HashTable();
	HashTable(const T);
	HashTable(const T*, UINT);
	HashTable(const HashTable&);
	HashTable<T, N>& operator = (const HashTable&);
	~HashTable();

	void Add(T);

	friend std::ostream& operator << (std::ostream& out, HashTable& ds) { ds.Print(); return out; }
};

HASH_TEMPLATE HashTable<T, N>::HashTable()
{
	this->Create();
}

HASH_TEMPLATE HashTable<T, N>::HashTable(const T data)
{
	this->Create();
	this->head[0] = Hash<T, N>(data);
	++this->size;
}

HASH_TEMPLATE HashTable<T, N>::HashTable(const T* arrayOfData, UINT arraySize)
{
	this->Create();
	for (int i = 0; i < arraySize; ++i)
		this->Add(arrayOfData[i]);
}

HASH_TEMPLATE HashTable<T, N>::HashTable(const HashTable& otherTable)
{
	this->Release();
	this->DeepCopy(otherTable);
}

HASH_TEMPLATE HashTable<T, N>& HashTable<T, N>::operator = (const HashTable& otherTable)
{
	this->Release();
	this->DeepCopy(otherTable);

	return *this;
}

HASH_TEMPLATE HashTable<T, N>::~HashTable()
{
	this->Release();
}

HASH_TEMPLATE void HashTable<T, N>::Create()
{
	this->head = new Hash<T, N>[TABLE_SIZE];
	this->size = 0;
}

HASH_TEMPLATE void HashTable<T, N>::Release()
{
	if (this->size)
	{
		Hash<T, N> *iterator, *holder;

		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			iterator = this->head[i].next;
			while (iterator != nullptr)
			{
				holder = iterator->next;
				delete iterator;
				iterator = holder;
			}
		}

		delete[] this->head;
		head = nullptr;
		this->size = 0;
	}
}

HASH_TEMPLATE Hash<T, N>* HashTable<T, N>::LastNodeInHash(const int arrayPos)
{
	if (this->size)
	{
		if (0 <= arrayPos && arrayPos < this->size)
		{
			Hash<T, N> *iterator = &this->head[arrayPos];
			while (iterator->next != nullptr)
				iterator = iterator->next;

			return iterator;
		}
	}

	return null;
}

HASH_TEMPLATE void HashTable<T, N>::DeepCopy(const HashTable<T, N>& otherTable)
{
	if (otherTable.size)
	{
		this->Release();
		this->Create();

		Hash<T, N> *iterator, *otherIterator;
		this->size = otherTable.size;

		for (int i = 0; i < otherTable.size; ++i)
		{
			this->head[i] = Hash<T, N>(otherTable.head[i]);
			otherIterator = &otherTable.head[i];
			while (otherIterator->next != nullptr)
			{
				iterator = &this->head[i];
				iterator->next = new Hash<T, N>(*otherIterator->next);
				otherIterator = otherIterator->next;
				iterator = iterator->next;
			}
		}
	}
}

HASH_TEMPLATE void HashTable<T, N>::Add(T data)
{
	if (this->size < TABLE_SIZE)
		this->head[this->size] = Hash<T, N>(data);
	else
	{
		Hash<T, N>* iterator = &head[this->size % TABLE_SIZE];
		while (iterator->next != nullptr)
			iterator = iterator->next;

		iterator->next = new Hash<T, N>(data);
	}

	++(this->size);
}

/*HASH_TEMPLATE void HashTable<T, N>::Add(T data, N key)
{
	//int place = 0;
	bool placed = false;
	for (int i = 0; i < this->size; ++i)
	{
		if (head[i].key == key)
		{
			Hash<T, N>* iterator = &head[i];
			while (iterator->next != nullptr)
				iterator = iterator->next;
			iterator->next = new Hash<T, N>(data, key);
			placed = true;
		}
	}

	if (!placed)
	{

	}
}//*/

HASH_TEMPLATE void HashTable<T, N>::Print()
{
	int depth;
	Hash<T, N>* iterator;

	for (int i = 0; i < this->size; ++i)
		if (i < TABLE_SIZE)
			std::cout << this->head[i] << " | ";
		else
		{
			depth = i / TABLE_SIZE;
			iterator = &this->head[i % TABLE_SIZE];
			while (depth)
			{
				iterator = iterator->next;
				--depth;
			}

			std::cout << *iterator << " | ";
		}
}

#endif