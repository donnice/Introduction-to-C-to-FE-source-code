// CallPayoff.hpp
//
// Class for payoff for call options (1 factor)
//
// (C) Shujie CHEN @2016

#ifndef CallPayoff_hpp
#define CallPayoff_hpp

#include "Payoff.hpp"

class CallPayoff: public Payoff
{
private:

	double K;	// Strike price

public:

	// Constructors and destructor
	CallPayoff();							// Default constructor
	CallPayoff(double strike);				
	CallPayoff(const CallPayoff& source);	// Copy constructor
	virtual ~CallPayoff();					// Destructor

	// Selectors
	double Strike() const;					// Return strike price
	 

}