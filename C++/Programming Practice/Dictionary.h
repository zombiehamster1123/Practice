#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Nodes.h"
#define DICT_SIZE 100

HASH_TEMPLATE
class Dictionary
{
private:
	Dict_Hash<T, N>* head = nullptr;
	int size = 0;

	void Create();
	void DeepCopy(const Dictionary<T, N>& otherDictionary);
	void Release();
	void Print();
	SingleNode<T>* LastNodeInHash(const int);

public:
	Dictionary();
	Dictionary(const N, const T);
	Dictionary(const N*, const T*, UINT);
	Dictionary(const Dictionary&);
	Dictionary<T, N>& operator = (const Dictionary&);
	~Dictionary();

	void Add(N, T);

	friend std::ostream& operator << (std::ostream& out, Dictionary& dict) { dict.Print(); return out; }
};

HASH_TEMPLATE Dictionary<T, N>::Dictionary()
{
	this->Create();
}

HASH_TEMPLATE Dictionary<T, N>::Dictionary(const N key, const T data)
{
	this->Create();
	this->head[0] = Dict_Hash<T, N>(key, data);
	this->size = 1;
}

HASH_TEMPLATE Dictionary<T, N>::Dictionary(const N* arrayOfKeys, const T* arrayOfData, UINT arraySize)
{
	this->Create();
	this->size = arraySize;
	for (int i = 0; i < arraySize; ++i)
		this->Add(arrayOfData[i], arrayOfKeys[i]);
}

HASH_TEMPLATE Dictionary<T, N>::Dictionary(const Dictionary& otherDict)
{
	this->DeepCopy(otherDict);
}

HASH_TEMPLATE Dictionary<T, N>& Dictionary<T, N>::operator = (const Dictionary& otherDict)
{
	this->DeepCopy(otherDict);

	return *this;
}

HASH_TEMPLATE Dictionary<T, N>::~Dictionary()
{
	this->Release();
}

HASH_TEMPLATE void Dictionary<T, N>::Create()
{
	this->head = new Dict_Hash<T, N>[DICT_SIZE];
	this->size = 0;
}

HASH_TEMPLATE void Dictionary<T, N>::Release()
{
	if (this->size)
	{
		SingleNode<T> *iterator, *holder;

		for (int i = 0; i < DICT_SIZE; ++i)
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
		this->head = nullptr;
		this->size = 0;
	}
}

HASH_TEMPLATE void Dictionary<T, N>::DeepCopy(const Dictionary<T, N>& otherDict)
{
	if (otherDict.size)
	{
		this->Release();
		this->Create();

		SingleNode<T> *nodeIterator, *otherNodeIterator;
		this->size = otherDict.size;

		for (int i = 0; i < this->size; ++i)
		{
			this->head[i] = Dict_Hash<T, N>(otherDict.head[i].key);
			otherNodeIterator = otherDict.head[i].next;
			this->head[i].next = new SingleNode<T>(otherNodeIterator->storedData);
			nodeIterator = this->head[i].next;
			otherNodeIterator = otherNodeIterator->next;
			while (otherNodeIterator != nullptr)
			{
				nodeIterator = new SingleNode<T>(otherNodeIterator->storedData);
				nodeIterator = nodeIterator->next;
				otherNodeIterator = otherNodeIterator->next;
			}
		}
	}
}

HASH_TEMPLATE void Dictionary<T, N>::Print()
{
	SingleNode<T>* iterator;

	for (int i = 0; i < DICT_SIZE; ++i)
	{
		if (this->head[i].key != NULL)
		{
			std::cout << "Key: " << this->head[i];
			iterator = this->head[i].next;
			if (iterator != nullptr)
			{
				std::cout << " Data: ";
				while (iterator != nullptr)
				{
					std::cout << *iterator << ", ";
					iterator = iterator->next;
				}
			}

			std::cout << "\b\b | ";
		}
	}

	std::cout << "\b\b ";
}

HASH_TEMPLATE SingleNode<T>* Dictionary<T, N>::LastNodeInHash(const int index)
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->head[i].next != nullptr && 0 <= index && index < this->size)
		{
			SingleNode<T>* iterator = this->head[i].next;
			while (iterator->next != nullptr)
				iterator = iterator->next;

			return iterator;
		}
	}

	return nullptr;
}

HASH_TEMPLATE void Dictionary<T, N>::Add(N key, T data)
{
	int lastPlace = -1;
	bool marked = false;
	N keyHolder;
	for (int i = 0; i < DICT_SIZE; ++i)
	{
		keyHolder = this->head[i].key;

		if (keyHolder == key)
		{
			SingleNode<T>* lastNode = this->LastNodeInHash(i);

			if (lastNode != nullptr)
				lastNode->next = new SingleNode<T>(data);

			++this->size;
			break;
		}
		else if (!marked && keyHolder == NULL)
		{
			lastPlace = i;
			marked = true;
		}
	}

	if (-1 < lastPlace && lastPlace < DICT_SIZE)
	{
		++this->size;
		this->head[lastPlace].key = key;
		this->head[lastPlace].next = new SingleNode<T>(data);
	}
}

#endif