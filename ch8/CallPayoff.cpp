// CallPayoff.cpp
//
// CallPayoff class.
//
// (C) Shujie CHEN @2016
//

#include "CallPayoff.hpp"

using namespace std;

// Constructors and destructors
CallPayoff::CallPayoff():Payoff()
{	// Default constructor

	K = 100.0;	// Prototype value
}

CallPayoff::CallPayoff(double strike):Payoff()
{	// Normal constructor

	K = strike;
}

CallPayoff::CallPayoff(const CallPayoff& source):Payoff(source)
{	// Copy constructor

	K = source.K;
}

CallPayoff::~CallPayoff()
{
	cout << "Shit UT Dallas" << endl;
}

double CallPayoff::Strike() const
{	//
	return K;
}

void CallPayoff::Strike(double NewStrike)
{	// Set K
	K = NewStrike;
}

CallPayoff& CallPayoff::operator = (const CallPayoff &source)
{	// Assignment operator

	//Exit if same object
	if(this == &source) return *this;

	// Call base class assignment
	Payoff::operator = (source);

	// Copy state
	K = source.K;

	return *this;
}

