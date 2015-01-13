#include <iostream>
#include <ostream>
#define UINT unsigned int
#define TEMPLATED template <class T>
#define ReleaseMacro(x) { if(x && x != nullptr){ delete x; x = nullptr; } }

TEMPLATED struct SingleNode
{
public:
	T storedData = NULL;
	SingleNode* next = nullptr;

	SingleNode() { this->storedData = NULL; this->next = nullptr; }
	SingleNode(const T data) { this->storedData = data; this->next = nullptr; }
	SingleNode(const T data, const SingleNode& node) { this->storedData = data; this->next = node; }
	SingleNode(const SingleNode& node) { this->storedData = node.storedData; this->next = node.next; }
	~SingleNode() { this->storedData = NULL; this->next = nullptr; }

	friend std::ostream& operator << (std::ostream& out, SingleNode& node) { std::cout << node.storedData; return out; }
	friend std::istream& operator >> (std::istream& in, SingleNode& node) { in >> node.storedData; return in; }
};

TEMPLATED struct DoubleNode
{
public:
	T storedData = NULL;
	DoubleNode* left = nullptr;
	DoubleNode* right = nullptr;

	DoubleNode() { this->storedData = NULL; this->left = nullptr; this->right = nullptr; }
	DoubleNode(const T data) { this->storedData = data; this->left = nullptr; this->right = nullptr; }
	DoubleNode(const T data, const DoubleNode& lowerNode, const DoubleNode& largerNode) { this->storedData = data; this->left = lowerNode; this->right = largerNode; }
	DoubleNode(const DoubleNode& node) { this->storedData = node.storedData; this->left = node.left; this->right = node.right; }
	~DoubleNode() { this->storedData = NULL; this->left = nullptr; this->right = nullptr; }

	friend std::ostream& operator << (std::ostream& out, DoubleNode& node) { std::cout << node.storedData; return out; }
	friend std::istream& operator >> (std::istream& in, DoubleNode& node) { in >> node.storedData; return in; }
};

TEMPLATED struct Hash
{
public:
	T storedData = NULL;
	int key = 0;
	Hash* next;

	Hash() { this->storedData = NULL; this->key = 0; this->next = nullptr; }
	Hash(const T data) { this->storedData = data; this->key = 0; this->next = nullptr; }
	Hash(const T data, const int key) { this->storedData = data; this->key = key; this->next = nullptr; }
	Hash(const T data, const int key, const Hash& hash) { this->storedData = data; this->key = key; this->next = hash; }
	Hash(const Hash& otherHash)  { this->storedData = otherHash.data; this->key = otherHash.key; this->next = otherHash.hash; }
	Hash<T>& operator = (const Hash<T>& otherHash) { this->storedData = otherHash.storedData; this->key = otherHash.key; this->next = otherHash.next; return *this;  }
	~Hash() { this->storedData = NULL; this->key = 0; this->next = nullptr; }

	friend std::ostream& operator << (std::ostream& out, Hash& node) { std::cout << node.storedData; return out; }
	friend std::istream& operator >> (std::istream& in, Hash& node) { in >> node.storedData; return in; }
};