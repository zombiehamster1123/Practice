#include "Stack.h"

class BinaryTree
{
private:
	DoubleNode<int>* root = nullptr;

	void Release(DoubleNode<int>*);
	void DeepCopy(const BinaryTree&);
	void CopyNode(DoubleNode<int>*, const DoubleNode<int>);
	void RecurssivePrint(DoubleNode<int>*);

public:
	BinaryTree();
	BinaryTree(const int);
	BinaryTree(int*, UINT);

	BinaryTree(const BinaryTree&);
	BinaryTree& operator = (const BinaryTree&);

	~BinaryTree();

	DoubleNode<int>* GetRoot() { return root; }
	void SetRoot(DoubleNode<int>* node) { root = node; }

	__declspec(property(get = GetRoot, put = SetRoot)) DoubleNode<int>* Root;

	void Add(int);
	void Print();

	friend std::ostream& operator << (std::ostream& out, BinaryTree& bt) { bt.Print(); return out; }
};