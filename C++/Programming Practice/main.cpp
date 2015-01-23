#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <fstream>
#include "PracticeMethods.h"
#include "Bitwise.h"
#include "Threads.h"
#include "Dictionary.h"
#include "Stack.h"
#include "HashTable.h"
#include "Tree.h"
#include "SmartPointers.h"
#include "AbstractFactory.h"

#define NEWLINE "\n"

using namespace std;

void TestPracticeMethods()
{
	string s = "Hello World!";
	cout << measure<>::execution(RecurssionReverseString, s) << "\n";
	cout << RecurssionReverseString(s) << "\n";

	MemoryReverseString(s);
	cout << s << "\n";

	int arr3[5] = { 9, 7, 11, 5, 1 };

	cout << "BubbleSort: ";

	BubbleSort(arr3, 5);

	for (int i = 0; i < 5; ++i)
		cout << " | " << arr3[i];

	cout << " | \n";

	int a[7] = { 1, 2, 5, 7, 0, 0, 0};
	int b[3] = { 3, 4, 6  };
	//BookMergeIntoArray(a, b, 4, 3);
	//cout << "Time: " << measure<>::execution(BookMergeIntoArray, a, b, 4, 3) << "\n";
	
	/*for (int i = 0; i < 7; ++i)
		cout << a[i] << ", ";//*/

	cout << SortAnagram("lasdfkj") << "\n";
}

void TestLinkedList()
{
	//SingleNode<int> node(5);
	//cout << "Node: " << node << "\n";
	SingleyLinkedList<int> ds(1);
	cout << "LinkedList1: " << ds << "\n";
	ds.Add(2);
	cout << "LinkedList1: " << ds << "\n";

	int arr[4] = { 1, 2, 3, 4 };
	SingleyLinkedList<int> ds2(arr, 4);
	cout << "LinkedList2: " << ds2 << "\n";

	int arr2[3] = { 5, 6, 7 };
	SingleyLinkedList<int> ds3(arr2, 3);
	cout << "LinkedList3: " << ds3 << "\n";

	ds3.Delete(3);
	cout << "LinkedList4: " << ds3 << "\n";
}

void TestStack()
{
	Stack<int> s1(1);
	cout << "Stack1: " << s1 << "\n";

	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << "Stack1: " << s1 << "\n";

	cout << "Popped: " << s1.Pop() << "\n";
	cout << "Stack1: " << s1 << "\n";//*/ 
}

void TestBinaryTree()
{
	BinaryTree<int> bt(10);
	cout << "Binary Tree: " << bt;
	cout << "Binary Tree Count: " << bt.Count();

	bt.Add(5);
	bt.Add(1);
	bt.Add(3);
	bt.Add(8);
	bt.Add(16);
	bt.Add(19);
	bt.Add(13);//*/
	cout << "Binary Tree: " << bt;
	cout << "Binary Tree Count: " << bt.Count();
	bt.DepthFirstSearch();
	bt.BreathedFirstSearch();

	/*BinaryTree<int> bt2;
	cout << "Binary Tree2: " << bt2;
	cout << "Binary Tree2 Count: " << bt2.Count();
	bt2 = bt;
	cout << "Binary Tree2: " << bt2;
	cout << "Binary Tree2 Count: " << bt2.Count();*/
}

void TestHashTable()
{
	HashTable<int, int> ht(10);
	ht.Add(1);
	ht.Add(15);
	cout << "Hash Table1: " << ht << NEWLINE;
	HashTable<int, int> ht2(123);
	ht2.Add(145);
	ht2.Add(156);
	ht2.Add(200);
	cout << "Hash Table2: " << ht2 << NEWLINE;

	ht = ht2;
	cout << "Hash Table1: " << ht << NEWLINE;
	cout << "Hash Table2: " << ht2 << NEWLINE;

	Dictionary<int, int> dt(1, 10);
	dt.Add(1, 112);
	dt.Add(2, 15);
	cout << "Dictionary: " << dt << NEWLINE;
	Dictionary<int, int> dt2(5, 16);
	cout << "Dictionary2: " << dt2 << NEWLINE;
	dt = dt2;
	cout << "Dictionary: " << dt << NEWLINE;
	cout << "Dictionary2: " << dt2 << NEWLINE;
}

void TestBitwise()
{
	cout << "Liam's Count Bits: " << liamCountBits(78) << "\n";
	cout << "My Count Bits: " << countBits(78) << "\n";

	/*bitOddEvenSwap(100);
	bookSwapOddEvenBits(100);*/
	cout << "Number of Flips: " << numFlipConverts(17, 28);
	cout << "Number of Flips: " << bookBitSwapRequired(17, 28);
}

void TestThreading()
{
	threadExampleOne();
	threadExampleTwo();
}

void TestSmartPointers()
{
	SmartPointer sp;

	sp.UseRawPointer();
	sp.UseUniquePointer();
	sp.UseSharedPointer();
	sp.UseWeakPointer();
}

void TestFactory()
{
	ConcreteFactory1 cf;

	cf.CreateAbstractProductA();
}

void TestFileIO(const char* fileName)
{
	ofstream outFile(fileName);
	if (outFile.is_open())
	{
		outFile << "I write in things because its fun\n";
		outFile << "Another line";
		outFile.close();
	}

	string line;
	ifstream inFile(fileName);
	if (inFile.is_open())
	{
		while (getline(inFile, line))
			cout << line << '\n';
		inFile.close();
	}
	else
		cout << "Unable to open file";
}

void program()
{
	//TestPracticeMethods();
	//TestLinkedList();
	//TestStack();
	TestBinaryTree();
	//TestBitwise();
	//TestThreading();	
	//TestHashTable();
	//TestSmartPointers();

	cout << "\nPress Enter to Continue\n";//*/
	cin.get();
}

//template<typename TimeFunction = measure<>::execution>
int main()
{
	program();
	_CrtDumpMemoryLeaks();
}