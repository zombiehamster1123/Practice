#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "PracticeMethods.h"
#include "HashTable.h"
#include "Bitwise.h"
#include "Threads.h"

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
	cout << "DataStructure: " << ds << "\n";
	ds.Add(2);
	cout << "DataStructure: " << ds << "\n";

	int arr[4] = { 1, 2, 3, 4 };
	SingleyLinkedList<int> ds2(arr, 4);
	cout << "DataStructure2: " << ds2 << "\n";

	int arr2[3] = { 5, 6, 7 };
	SingleyLinkedList<int> ds3(arr2, 3);
	cout << "DataStructure3: " << ds3 << "\n";

	cout << "DataStructure3: " << arr2[4] << "\n";
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
	BinaryTree bt(10);
	cout << "Binary Tree: " << bt;

	bt.Add(5);
	bt.Add(1);
	bt.Add(3);
	bt.Add(8);
	bt.Add(16);
	bt.Add(19);
	bt.Add(13);//*/
	cout << "Binary Tree: " << bt;
}

void TestHashTable()
{
	HashTable<int, int> ht(10);
	ht.Add(1);
	ht.Add(15);
	cout << "Hash Table1: " << ht << NEWLINE;//*/
	HashTable<int, int> ht2(123);
	ht2.Add(145);
	ht2.Add(156);
	ht2.Add(200);
	cout << "Hash Table2: " << ht2 << NEWLINE;

	ht = ht2;
	cout << "Hash Table1: " << ht << NEWLINE;
	cout << "Hash Table2: " << ht2 << NEWLINE;
}

void TestBitwise()
{
	cout << "Liam's Count Bits: " << liamCountBits(78) << "\n";
	cout << "My Count Bits: " << countBits(78) << "\n";
}

void TestThreading()
{
	threadExampleOne();
	threadExampleTwo();
}

void program()
{
	TestPracticeMethods();
	//TestLinkedList();
	//TestStack();
	/*TestBinaryTree();
	TestBitwise();
	TestThreading();*/	
	TestHashTable();

	cout << "\nPress Enter to Continue\n";//*/
	cin.get();
}

//template<typename TimeFunction = measure<>::execution>
int main()
{
	program();
	_CrtDumpMemoryLeaks();
}