#include "Tree.h"
#define TABLE_SIZE 2

TEMPLATED
class HashTable
{
private:
	Hash<T>* head = nullptr;
	int size = 0;

	void Create();
	void DeepCopy(const HashTable<T>& otherTable);
	void Release();
	void Print();

public:
	HashTable();
	HashTable(const T);
	HashTable(const T*, UINT);
	HashTable(const HashTable&);
	HashTable<T>& operator = (const HashTable&);
	~HashTable();

	void Add(T);

	friend std::ostream& operator << (std::ostream& out, HashTable& ds) { ds.Print(); return out; }
};

TEMPLATED HashTable<T>::HashTable()
{
	this->Create();
}

TEMPLATED HashTable<T>::HashTable(const T data)
{
	this->Create();
	this->head[0] = Hash<T>(data);
	++this->size;
}

TEMPLATED HashTable<T>::HashTable(const T* arrayOfData, UINT arraySize)
{
	this->Create();
	for (int i = 0; i < arraySize; ++i)
		this->Add(arrayOfData[i]);
}

TEMPLATED HashTable<T>::HashTable(const HashTable& otherTable)
{
	this->Release();
	this->DeepCopy();
}

TEMPLATED HashTable<T>& HashTable<T>::operator = (const HashTable&)
{
	this->Release();
	this->DeepCopy();

	return *this;
}

TEMPLATED HashTable<T>::~HashTable()
{
	this->Release();
}

TEMPLATED void HashTable<T>::Create()
{
	this->head = new Hash<T>[TABLE_SIZE];
	this->size = 0;
}

TEMPLATED void HashTable<T>::Release()
{
	Hash<T> *iterator, *holder;

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
	this->size = 0;
}

TEMPLATED void HashTable<T>::DeepCopy(const HashTable<T>& otherTable)
{
	if (this->size > 0)
	{
		this->Release();
		Hash<T> iterator = head;

		if (otherTable.size < TABLE_SIZE)
			int intHolder = otherTable.size;
		else
			int intHolder = TABLE_SIZE;

		for (int i = 0; i < intHolder; ++i)
		{
			this->head[i] = new Hash<T>(otherTable.head[i]);
			iterator = this->head[i];
			while (iterator->next != nullptr)
			{
				iterator->next = new Hash<T>(iterator->next);
				iterator = iterator->next;
			}
		}

		this->size = otherTable.size;
	}
}

TEMPLATED void HashTable<T>::Add(T data)
{
	if (this->size < TABLE_SIZE)
		this->head[this->size] = Hash<T>(data);
	else
	{
		Hash<T>* iterator = &head[this->size % TABLE_SIZE];
		while (iterator->next != nullptr)
			iterator = iterator->next;

		iterator->next = new Hash<T>(data);
	}

	++(this->size);
}

TEMPLATED void HashTable<T>::Print()
{
	int depth;
	Hash<T>* iterator;

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