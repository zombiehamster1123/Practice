#include "SmartPointers.h"

#define NEWLINE "\n"

using namespace std;

void SmartPointer::UseRawPointer()
{
	// Use a raw pointer --- not recommended
	int* nInt = new int(1);

	// Use nInt
	cout << *nInt << NEWLINE;

	// Delete the memory
	delete nInt;
}

void SmartPointer::UseUniquePointer()
{
	// Declare a smart pointer on stack and pass it the raw pointer
	unique_ptr<int> nInt(new int(2));

	// Use nInt...
	cout << "Unique Pointer 1: " << *nInt.get() << NEWLINE;

	std::unique_ptr<int> p1(new int(10));
	//std::unique_ptr<int> p2 = p1;	//Compile error
	cout << "Unique Pointer 2: " << *p1.get() << NEWLINE;
	std::unique_ptr<int> p3 = std::move(p1); //Transfers ownership. p3 now owns the memory and p1 is rendered invalid.
	cout << "Unique Pointer 3: " << *p3.get() << NEWLINE;
	cout << "Unique Pointer 2: " << p1.get() << NEWLINE;
	//cout << *p1.get() << NEWLINE;	// Compile error

	p3.reset(); //Deletes the memory.
	p1.reset(); //Does nothing.
}

// http://msdn.microsoft.com/en-us/library/hh279669.aspx
void SmartPointer::UseSharedPointer()
{
	// Use make_shared function when possible
	auto sp1 = make_shared<int>(3);

	cout << "Auto: " << *sp1.get() << NEWLINE;

	// Ok, but slightly less efficient
	// Note: Using new expression as constructor argument
	// creates no named variable for other code to access
	shared_ptr<int> sp2(new int(4));

	cout << "Shared Pointer 1: " << *sp2.get() << NEWLINE;

	// When initialization be separate from declaration, e.g. class members,
	// initialize with nullptr to make your programming intent explicit
	shared_ptr<int> sp3(nullptr);

	// Equivalent to: shared_ptr<int> sp3
	sp3 = make_shared<int>(5);

	cout << "Shared Pointer 2: " << *sp3.get() << NEWLINE;

	// http://en.wikipedia.org/wiki/Smart_pointer
	shared_ptr<int> p1(new int(5));
	shared_ptr<int> p2 = p1; //Both now own the memory.

	p1.reset(); //Memory still exists, due to p2.
	p2.reset(); //Deletes the memory, since no one else owns the memory.
}

void SmartPointer::UseWeakPointer()
{
	// http://en.wikipedia.org/wiki/Smart_pointer
	shared_ptr<int> p1(new int(5));
	weak_ptr<int> wp1 = p1;	// p1 owns the memory

	shared_ptr<int> p2 = wp1.lock();	// Now p1 and p2 own the memory
	if (p2)	// As p2 is initialized from a weak pointer, you have to check if the memory still exist
	{
		// Do something with p2
		cout << "Shared Pointer with a weak pointer: " << *p2.get() << NEWLINE;
	}

	p1.reset();	// Memory is deleted

	shared_ptr<int> p3 = wp1.lock();	// Memory is gone, so we get an empty shared_ptr

	if (p3)
	{
		// Will not execute this
		cout << "Shared Pointer2 with a weak pointer: " << *p3.get() << NEWLINE;
	}
}