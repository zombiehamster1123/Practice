#include <iostream>
#include <ostream>
#define UINT unsigned int
#define TEMPLATED template <class T>
#define HASH_TEMPLATE template<class T, class N>
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

HASH_TEMPLATE struct Hash
{
public:
	T storedData = NULL;
	N key = NULL;
	Hash* next;

	Hash() { this->storedData = NULL; this->key = NULL; this->next = nullptr; }
	Hash(const T data) { this->storedData = data; this->key = NULL; this->next = nullptr; }
	Hash(const T data, N key) { this->storedData = data; this->key = key; this->next = nullptr; }
	Hash(const T data, N key, const Hash& hash) { this->storedData = data; this->key = key; this->next = hash; }
	Hash(const Hash& otherHash)  { this->storedData = otherHash.storedData; this->key = otherHash.key; this->next = otherHash.next; }
	Hash<T, N>& operator = (const Hash<T, N>& otherHash) { this->storedData = otherHash.storedData; this->key = otherHash.key; this->next = otherHash.next; return *this;  }
	~Hash() { this->storedData = NULL; this->key = NULL; this->next = nullptr; }

	friend std::ostream& operator << (std::ostream& out, Hash& node) { std::cout << node.storedData; return out; }
	friend std::istream& operator >> (std::istream& in, Hash& node) { in >> node.storedData; return in; }
};

HASH_TEMPLATE struct Dict_Hash
{
public:
	N key = NULL;
	SingleNode<T>* next;

	Dict_Hash() { this->key = NULL; this->next = nullptr; }
	Dict_Hash(N key) { this->storedData = data; this->key = key; this->next = nullptr; }
	Dict_Hash(N key, const Dict_Hash& hash) { this->storedData = data; this->key = key; this->next = hash; }
	Dict_Hash(const Dict_Hash& otherHash)  { this->key = otherHash.key; this->next = otherHash.hash; }
	Dict_Hash<T, N>& operator = (const Dict_Hash<T, N>& otherHash) { this->key = otherHash.key; this->next = otherHash.next; return *this; }
	~Dict_Hash() { this->key = NULL; this->next = nullptr; }

	friend std::ostream& operator << (std::ostream& out, Dict_Hash& node) { std::cout << node.storedData; return out; }
	friend std::istream& operator >> (std::istream& in, Dict_Hash& node) { in >> node.storedData; return in; }
};