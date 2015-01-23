#ifndef PRODUCTA1_H
#define PRODUCTA1_H

#include "AbstractProductA.h"

class ProductA1 : public AbstractProductA
{
public:
	ProductA1();
	ProductA1(const ProductA1&);
	ProductA1& operator = (const ProductA1&);
	~ProductA1();

	friend std::ostream& operator << (std::ostream& out, ProductA1& pa) { pa.Print(); return out; }
};

#endif