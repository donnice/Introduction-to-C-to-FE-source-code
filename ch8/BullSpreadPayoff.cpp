// BullSpreadPayoff.cpp
//
// Classes for payoff for BullSpreadPayoff
//
// (C) Shujie CHEN @2016

#include "BullSpreadPayoff.hpp"


using namespace std;
// Constructor and destructor
BullSpreadPayoff::BullSpreadPayoff(): Payoff()
{ // Default constructor

	K1 = K2 = 100.0; // Prototype value
	buyValue = 3.0;
	sellValue = 1.0;
}

BullSpreadPayoff::BullSpreadPayoff(double strike1, double strike2,
						double BuyValue, double SellValue):Payoff()
{ // Normal constructor and destructor

	K1 = strike1;
	K2 = strike2;

	buyValue = BuyValue;
	sellValue = SellValue;
}

BullSpreadPayoff::BullSpreadPayoff(const BullSpreadPayoff& source):Payoff(source)
{ // Copy constructor

	K1 = source.K1;
	K2 = source.K2;

	buyValue = source.buyValue;
	sellValue = source.sellValue;
}

BullSpreadPayoff::~BullSpreadPayoff()
{ // Destructor
	cout << "I am destructed!" << endl;
}

