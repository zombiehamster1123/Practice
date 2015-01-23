#ifndef ABSTRACTPRODUCTA_H
#define ABSTRACTPRODUCTA_H

#include "UniversalHeaders.h"

class AbstractProductA
{
protected:
	int data;

	virtual void Reset();
	virtual void Copy(const AbstractProductA&);

public:
	AbstractProductA();
	AbstractProductA(const AbstractProductA&);
	AbstractProductA& operator = (const AbstractProductA&);
	~AbstractProductA();

	virtual void Print();
	friend std::ostream& operator << (std::ostream& out, AbstractProductA& pa) { pa.Print(); return out; }
};


#endif