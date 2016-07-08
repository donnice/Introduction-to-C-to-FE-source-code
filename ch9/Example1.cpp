// Example1.cpp
//
// page 151 Run-time behavior of C++
//
// learned type_id, which can help us to know the type of a class
// And casting, which is converting an object pointer of one class to another
//
// End at p157
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
	virtual double calculate(double d) const = 0;

	void doIt() { cout << "in base\n"; }
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

	if(typeid(d1) != typeid(d2))
	{
		cout << "Types are NOT the same!" << endl;
	}

	Base* b = &d1;
	const type_info& myRef2 = typeid(*b);

	cout << "Human readable name:" << myRef.name() << endl;

	// Create an array of Base class pointers
	int size = 10;
	Base *myArr[10];	// An array of pointers

	for (int j = 0; j < 6; j++)
	{
		myArr[j] = &d1;
	}

	for (int k = 6; k < size; k++)
	{
		myArr[k] = &d2;
	}

	// Now 'filter' the 'real' types
	int counterD1 = 0;
	int counterD2 = 0;


	for (int i = 0; i < size; i++)
	{
		if(typeid(*myArr[i]) == typeid(D1))
		{
			cout << "We have a D1!\n";
			counterD1++;
		}

		if(typeid(*myArr[i]) == typeid(D2))
		{
			cout << "We have a D2!\n";
			counterD2++;
		}
	}

	cout << "Number of D1s:" << counterD1 << endl;
	cout << "Number of D2s:" << counterD2 << endl;


	// dynamic casting
	D1 d1A;
	Base* base2 = &d1A;

	D1* d1Cast = dynamic_cast<D1*> (base2);

	if (d1Cast == 0)
	{
		cout << "Cast not possible!" << endl;
	}
	else
	{ // This function get called

		cout << "Cast is possible:" << endl;
		d1Cast -> print();
	}

	// Now cast a D1 to a D2 (not possible)
	D2 *d2Cast = dynamic_cast<D2*> (base2);
	if (d2Cast == 0)
		cout << "Case not possible!" << endl;
	else
	{
		cout << "Cast is possible:" << endl;
		d2Cast -> print();
	}

	// Upcasting
	D1* dd = new D1;
	Base* b3 = dynamic_cast<Base*>(dd);

	if (b3 == 0)
	{
		cout << "Cast not possible!" << endl;
	}	
	else
	{
		cout << "Cast is possible:" << endl;
		b3 -> print();
		b3 -> doIt();
	}
	delete dd;

	// Static casting
	Base* bA = &d1;
	Base* bB = &d2;

	D1* dA = static_cast<D1*>(bA);

	// Unsafe static cast
	cout << "Unsafe cast ..." << endl;
	D1* dB = static_cast<D1*> (bB);
	dB -> print();

	// Const Cast
	cout << "\n const cast stuff \n";
	D1 dAny;
	const Base* bConst = &dAny;
	bConst -> print();

	Base* bNonConst = const_cast<Base*>(bConst);
	bNonConst->print();

	// static, dynamic, reinterpret doesn't work

	cout << "\n Reinterpret cast stuff\n";

	D2 d2Any;
	Base* bb = reinterpret_cast<Base*>(&d2Any);
	bb->print();

	return 0;
}