// Payoff.hpp
//
// Base class for Payoffs.
//
// (C) Shujie CHEN @2016
//

#ifndef Payoff_hpp
#define Payoff_hpp

#include <iostream>
using namespace std;

class Payoff
{
public:
	// Constructors and destructor
	Payoff();						// Default constructor
	Payoff(const Payoff& source);	// Copy constructor
	virtual ~Payoff();				// Destructor

	// Operator overloading
	Payoff& operator = (const Payoff& source);	// Assignment Operator

	// Pure virtual payoff function
	virtual double payoff(double S) const = 0;	// For a given spot price
};

#endif
