// Example1.cpp
//
// page 151 Run-time behavior of C++
//
// (C) Shujie CHEN @2016
//

#include <iostream>
using namespace std;

#include <typeinfo>			// RTTI stuff

class Base
{

public:
	Base() {}
	virtual ~Base(){}

	virtual void print() const
	{
		cout << "I'm base!\n";
	}
};

class D1:public Base
{

public:
	D1(){}
	virtual ~D1(){}

	virtual void print() const
	{
		cout << "I'm a D1!\n";
	}

	virtual double calculate(double d) const
	{
		return 1.0*d;
	}
};

class D2: public Base
{
public:
	D2(){}
	virtual ~D2(){}

	virtual void print() const
	{
		cout << "I'm D2!\n";
	}

	virtual double calculate(double d) const
	{
		return 2.0*d;
	}

};

int main()
{

	// part I: typeinfo

	D1 d1, d11;
	D2 d2;

	// Define a reference to type
	const type_info& myRef = typeid(d1);

	cout << "Human readable name:" << myRef.name() << endl;

	// Test if two objects are of same type or not
	if(typeid(d1) == typeid(d11))
	{
		cout << "Typees are the same!" << endl;
	}

	


	return 0;
}