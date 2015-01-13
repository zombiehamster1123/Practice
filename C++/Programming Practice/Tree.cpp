#include "Tree.h"

BinaryTree::BinaryTree() : root(nullptr) { }

BinaryTree::BinaryTree(const int data)
{
	this->root = new DoubleNode<int>(data);
}

BinaryTree::BinaryTree(int* arrayOfData, UINT arraySize)
{
	root = new DoubleNode<int>(arrayOfData[0]);

	for (int i = 1; i < arraySize; ++i)
		Add(arrayOfData[i]);
}

BinaryTree::BinaryTree(const BinaryTree& otherBinaryTree)
{
	this->DeepCopy(otherBinaryTree);
}

BinaryTree& BinaryTree::operator = (const BinaryTree& otherBinaryTree)
{
	BinaryTree tmp = BinaryTree(otherBinaryTree);
	std::swap(root, tmp.root);

	return *this;
}

BinaryTree::~BinaryTree() { this->Release(this->root); }

void BinaryTree::CopyNode(DoubleNode<int>* destination, const DoubleNode<int> source)
{
	destination = new DoubleNode<int>(source);

	if (source.left != nullptr)
		CopyNode(destination->left, *source.left);

	if (source.right != nullptr)
		CopyNode(destination->right, *source.right);
}

void BinaryTree::DeepCopy(const BinaryTree& otherBinaryTree)
{
	this->Release(this->root);
	CopyNode(this->root, *otherBinaryTree.root);
}

void BinaryTree::Release(DoubleNode<int>* source)
{
	if (source->left != nullptr)
		Release(source->left);

	if (source->right != nullptr)
		Release(source->right);

	delete source;
}

void BinaryTree::Add(int data)
{
	DoubleNode<int>* iterator = root;

	while (true)
	{
		if (data <= iterator->storedData)
			if (iterator->left != nullptr)
				iterator = iterator->left;
			else
			{
				iterator->left = new DoubleNode<int>(data);
				break;
			}
		else
			if (iterator->right != nullptr)
				iterator = iterator->right;
			else
			{
				iterator->right = new DoubleNode<int>(data);
				break;
			}
	}
}

void BinaryTree::RecurssivePrint(DoubleNode<int>* node)
{
	if (node->left != nullptr)
		RecurssivePrint(node->left);

	std::cout << node->storedData << " | ";

	if (node->right != nullptr)
		RecurssivePrint(node->right);
}

void BinaryTree::Print()
{
	RecurssivePrint(this->root);
	std::cout << "\n";
}