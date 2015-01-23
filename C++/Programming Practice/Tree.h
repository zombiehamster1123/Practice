#ifndef TREE_H
#define TREE_H

#include "Nodes.h"

TEMPLATED class BinaryTree
{
private:
	DoubleNode<T>* root = nullptr;

	void Release(DoubleNode<T>*);
	void DeepCopy(const BinaryTree&);

	// Recurssive Helper Methods
	void CopyNode(DoubleNode<T>*, DoubleNode<T>*);
	void RecurssivePrint(DoubleNode<T>*);
	void DepthSearch(DoubleNode<T>*, DoubleNode<T>*, unsigned int&);
	int CountNode(DoubleNode<T>*);

public:
	BinaryTree();
	BinaryTree(const int);
	BinaryTree(int*, UINT);

	BinaryTree(const BinaryTree&);
	BinaryTree& operator = (const BinaryTree&);

	virtual ~BinaryTree();

	DoubleNode<T>* GetRoot() { return root; }
	void SetRoot(DoubleNode<T>* node) { root = node; }
	__declspec(property(get = GetRoot, put = SetRoot)) DoubleNode<T>* Root;

	void Add(int);
	void Print();
	int Count();

	DoubleNode<T>* BreathedFirstSearch();
	DoubleNode<T>* DepthFirstSearch();

	friend std::ostream& operator << (std::ostream& out, BinaryTree& bt) { bt.Print(); return out; }
};

TEMPLATED BinaryTree<T>::BinaryTree() : root(nullptr) { }

TEMPLATED BinaryTree<T>::BinaryTree(const int data)
{
	this->root = new DoubleNode<T>(data);
}

TEMPLATED BinaryTree<T>::BinaryTree(int* arrayOfData, UINT arraySize)
{
	this->root = new DoubleNode<T>(arrayOfData[0]);

	for (int i = 1; i < arraySize; ++i)
		Add(arrayOfData[i]);
}

TEMPLATED BinaryTree<T>::BinaryTree(const BinaryTree& otherBinaryTree)
{
	this->DeepCopy(otherBinaryTree);
}

TEMPLATED BinaryTree<T>& BinaryTree<T>::operator = (const BinaryTree& otherBinaryTree)
{
	BinaryTree tmp = BinaryTree(otherBinaryTree);
	swap(this->root, tmp.root);

	return *this;
}

TEMPLATED BinaryTree<T>::~BinaryTree() { this->Release(this->root); }

TEMPLATED void BinaryTree<T>::CopyNode(DoubleNode<T>* destination, DoubleNode<T>* source)
{
	if (destination != nullptr && source != nullptr)
	{
		if (source->left != nullptr)
		{
			destination->left = new DoubleNode<T>(source->left->storedData);
			CopyNode(destination->left, source->left);
		}

		if (source->right != nullptr)
		{
			destination->right = new DoubleNode<T>(source->right->storedData);
			CopyNode(destination->right, source->right);
		}
	}
}

TEMPLATED void BinaryTree<T>::DeepCopy(const BinaryTree& otherBinaryTree)
{
	if (otherBinaryTree.root != nullptr)
	{
		this->Release(this->root);
		this->root = new DoubleNode<T>(otherBinaryTree.root->storedData);
		CopyNode(this->root, otherBinaryTree.root);
	}
}

TEMPLATED void BinaryTree<T>::Release(DoubleNode<T>* source)
{
	if (source != nullptr)
	{
		if (source->left != nullptr)
			Release(source->left);

		if (source->right != nullptr)
			Release(source->right);

		delete source;
	}
}

TEMPLATED void BinaryTree<T>::Add(int data)
{
	DoubleNode<T>* iterator = root;

	// Find the lowest branch
	while (true)
	{
		if (data <= iterator->storedData)
			if (iterator->left != nullptr)
				iterator = iterator->left;
			else
			{
				iterator->left = new DoubleNode<T>(data);
				break;
			}
		else
			if (iterator->right != nullptr)
				iterator = iterator->right;
			else
			{
				iterator->right = new DoubleNode<T>(data);
				break;
			}
	}
}

TEMPLATED void BinaryTree<T>::RecurssivePrint(DoubleNode<T>* node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
			RecurssivePrint(node->left);

		std::cout << node->storedData << " | ";

		if (node->right != nullptr)
			RecurssivePrint(node->right);
	}
}

TEMPLATED void BinaryTree<T>::Print()
{
	RecurssivePrint(this->root);
	std::cout << "\n";
}

TEMPLATED int BinaryTree<T>::CountNode(DoubleNode<T>* target)
{
	if (target != nullptr)
		return 1 + CountNode(target->left) + CountNode(target->right);

	return 0;
}

TEMPLATED int BinaryTree<T>::Count()
{
	if (this->root != nullptr)
		return 1 + CountNode(this->root->left) + CountNode(this->root->right);

	return 0;
}

TEMPLATED void BinaryTree<T>::DepthSearch(DoubleNode<T>* numbers, DoubleNode<T>* node, unsigned int& prev)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			numbers[++prev] = node->left->storedData;
			DepthSearch(numbers, node->left, prev);
		}

		if (node->right != nullptr)
		{
			numbers[++prev] = node->right->storedData;
			DepthSearch(numbers, node->right, prev);
		}
	}
}

TEMPLATED DoubleNode<T>* BinaryTree<T>::DepthFirstSearch()
{
	if (this->root != nullptr)
	{
		DoubleNode<T>* numbers = new DoubleNode<T>[this->Count()];
		numbers[0] = *this->root;
		unsigned int x = 0;
		this->DepthSearch(numbers, this->root, x);

		// Double Checking
		cout << "Depth: ";
		for (int i = 0; i < this->Count(); ++i)
			cout << numbers[i] << ", ";
		cout << "\n";

		return numbers;
	}

	return nullptr;
}

TEMPLATED DoubleNode<T>* BinaryTree<T>::BreathedFirstSearch()
{
	if (this->root != nullptr)
	{
		int size = this->Count();
		int last = 0;
		int largest = 0;

		DoubleNode<T>* elements = new DoubleNode<T>[size];
		elements[0] = DoubleNode<T>(*this->root);

		for (int i = 0; i < size; ++i)
		{
			if (elements[i].left != nullptr)
				elements[++largest] = DoubleNode<T>(*elements[i].left);

			if (elements[i].right != nullptr)
				elements[++largest] = DoubleNode<T>(*elements[i].right);
		}

		// Double Checking
		cout << "Breadth: ";
		for (int i = 0; i < this->Count(); ++i)
			cout << elements[i] << ", ";
		cout << "\n";

		return elements;
	}

	return nullptr;
}

#endif