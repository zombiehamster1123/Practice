#include "ProductA1.h"

ProductA1::ProductA1()
{
	this->Reset();
}

ProductA1::ProductA1(const ProductA1& other)
{
	this->Copy(other);
}

ProductA1& ProductA1::operator= (const ProductA1& other)
{
	this->Copy(other);
	return *this;
}

ProductA1::~ProductA1()
{
	this->Reset();
}