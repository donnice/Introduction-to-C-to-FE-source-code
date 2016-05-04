// TestEuropeanOption.cpp
//
// Test program for the solutions of European Option pricing problems
//
// (C) Shujie CHEN @2016
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// All options are European

	// Call option on a stock
	EuropeanOption callOption;
	cout << "Call option on a stock: " << callOption.Price() << endl;

	// Put option on a stock index
	EuropeanOption indexOption;
	indexOption.optType = "P";
	indexOption.U = 100.0;
	indexOption.K = 95.0;

}