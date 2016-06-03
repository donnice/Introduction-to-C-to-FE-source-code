// BullSpreadPayoff.hpp
//
// Classes for payoff for call options
//
// (C) Shujie CHEN @2016
//

#ifndef BullSpreadPayoff_hpp
#define BullSpreadPayoff_hpp

#include "Payoff.hpp"

class BullSpreadPayoff:public Payoff
{
private:

	double K1;	// Strike price 1
	double K2;	// Strike price 2

	double buyValue;	// cost to buy
	double sellValue;	// sell value
public:

	// Constructors and destructor
	BullSpreadPayoff();
	BullSpreadPayoff(double strike1, double strike2,
					 double BuyVal, double SellVal);
	BullSpreadPayoff(const BullSpreadPayoff& source);
	virtual ~BullSpreadPayoff();

	// Selectors
	double Strike1() const;
	double Strike2() const;

	// Modifiers
	void Strike1(double NewStrike1);
	void Strike2(double NewStrike2);

	BullSpreadPayoff& operator = (const BullSpreadPayoff& source);

	double payoff(double S) const;
	double profit(double S) const;
};

#endif