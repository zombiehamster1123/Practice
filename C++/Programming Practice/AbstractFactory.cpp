#include "AbstractFactory.h"

AbstractFactory::AbstractFactory()
{
}

AbstractFactory::AbstractFactory(const AbstractFactory& other)
{
	*this = other;
}

AbstractFactory& AbstractFactory::operator = (const AbstractFactory& other)
{
	*this = other;
	return *this;
}

AbstractFactory::~AbstractFactory()
{
}

ConcreteFactory1::ConcreteFactory1()
{
}

ConcreteFactory1::~ConcreteFactory1()
{
}

AbstractProductA* ConcreteFactory1::CreateAbstractProductA()
{
	return new ProductA1();
}

//AbstractProductB& ConcreteFactory1::CreateAbstractProductB()
//{
//
//}