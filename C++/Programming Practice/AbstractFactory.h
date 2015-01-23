#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "UniversalHeaders.h"
#include "ProductA1.h"

class AbstractFactory
{
public:
	AbstractFactory();
	AbstractFactory(const AbstractFactory&);
	AbstractFactory& operator = (const AbstractFactory&);
	~AbstractFactory();

	// Abstract methods that all inherited classes must overwrite!!!
	virtual AbstractProductA* CreateAbstractProductA() = 0;
	//virtual AbstractProductB& CreateAbstractProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();

	AbstractProductA* CreateAbstractProductA();
	//AbstractProductB& CreateAbstractProductB();
};

//class ConcreteFactory2 : public AbstractFactory
//{
//public:
//	ConcreteFactory2();
//	~ConcreteFactory2();
//
//	AbstractProductA& CreateAbstractProductA();
//	//AbstractProductB& CreateAbstractProductB();
//};

//class AbstractProductB
//{
//protected:
//	std::string data;
//
//public:
//	AbstractProductB();
//	AbstractProductB(const AbstractProductB&);
//	AbstractProductB& operator = (const AbstractProductB&);
//	~AbstractProductB();
//};
//
//class ProductB1 : public AbstractProductB
//{
//public:
//	ProductB1();
//	~ProductB1();
//
//	void Print();
//
//	friend std::ostream& operator << (std::ostream& out, ProductB1& pb) { pb.Print(); return out; }
//};
//
//class ProductA2 : public AbstractProductA
//{
//public:
//	ProductA2();
//	~ProductA2();
//};
//
//class ProductB2 : public AbstractProductB
//{
//public:
//	ProductB2();
//	~ProductB2();
//};

#endif