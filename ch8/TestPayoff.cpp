// TestPayoff.cpp
//
// Testing the one factor payoff classes
//
// (C) Shujie CHEN @2016
//

#include "CallPayoff.hpp"
#include "BullSpreadPayoff.hpp"

using namespace std;

int main()
{
	CallPayoff call(20.0);

	cout << "Give a stock price (Plain Call):";
	double S;
	cin >> S;

	cout << "Call Payoff is: " << call.payoff(S) << endl;

	double K1 = 30.0;		// Strike price of bought call
	double K2 = 35.0;		// Strike price of sell call
	double costBuy = 3.0	// Cost to buy a call;
	double sellPrice = 1.0; // Sell price for call
	
}