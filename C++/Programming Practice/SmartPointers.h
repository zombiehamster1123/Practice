#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>
#include <memory>

// http://msdn.microsoft.com/en-us/library/hh279674.aspx
class SmartPointer
{
public:
	void UseRawPointer();
	void UseUniquePointer();
	void UseSharedPointer();
	void UseWeakPointer();
};

#endif