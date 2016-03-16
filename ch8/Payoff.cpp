// Payoff.cpp
//
// Base class for Payoffs.
//
// (C) Shujie CHEN @2016

#include "Payoff.hpp"

// Constructors and destructor
Payoff::Payoff()
{
	// Default constructor
}

Payoff::Payoff(const Payoff& source)
{
	// Copy constructor
}

Payoff::~Payoff()
{
	// Destructor
}

Payoff& Payoff::operator = (const Payoff& source)
{	// Assignment operator
	if(this == &source)
		return *this;

	return *this;
}