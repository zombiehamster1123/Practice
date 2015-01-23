#include "AbstractProductA.h"

#pragma region Constructors/ Destructor

AbstractProductA::AbstractProductA() 
{
	this->Reset();
}

AbstractProductA::AbstractProductA(const AbstractProductA& other)
{
	this->Copy(other);
}

AbstractProductA& AbstractProductA::operator = (const AbstractProductA& other)
{
	this->Copy(other);

	return *this;
}

AbstractProductA::~AbstractProductA()
{
	this->Reset();
}

#pragma endregion

#pragma region Protected Methods

void AbstractProductA::Reset()
{
	this->data = 0;
}

void AbstractProductA::Copy(const AbstractProductA& other)
{
	this->data = other.data;
}

#pragma endregion

// Output
void AbstractProductA::Print()
{
	std::cout << typeid(*this).name() << " : " << this->data << "\n";
}