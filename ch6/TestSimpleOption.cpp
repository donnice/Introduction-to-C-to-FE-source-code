// TestSimpleOption.cpp
//
// memory management in c++
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <string>

using namespace std;

class SimpleOption
{
public:
	double T;
	double K;
	// ...

	SimpleOption()
	{
		T = 1.0;
		K = 100;
	}
	virtual ~SimpleOption();

	void print() const
	{ // Read contents of option

		cout << "Expiry: " << T << ", Strike:" << K << endl;
	}
};

SimpleOption::~SimpleOption()
{
	cout << "SimpleOption is destructed." << endl;
}

int main()
{
	{ // Define a scope
		SimpleOption opt1;
		opt1.print();
	}

	SimpleOption myPortfolio[10];

	for(int j = 0; j < 10; j++)
	{
		myPortfolio[j].print();
	}

	// myPortfolio[-1].print();
	// myPortfolio[1000].print();

	cout << "======================================" << endl;

	SimpleOption* opt;
	SimpleOption* opt2;

	// Call default constructor
	opt = new SimpleOption;
	// OR error: member reference type 'SimpleOption *' is a pointer; maybe you meant to use '->'?
	opt->print();
	(*opt).print();


	return 0;
}