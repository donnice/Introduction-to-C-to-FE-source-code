// EuropeanOption.cpp
//
// Author: Daniel Duffy
//
// Black–Scholes model
//
// (C) Shujie CHEN @2016
//	


#include "EuropeanOption.hpp"	// Declarations of functions
				// For mathematical functions, exp()
#include <cmath>
#include <string>

using namespace std;

// Kernel Functions
double N(double x)
{
	if(x < 0)
		return 0;
	else if(x > 0 && x < 1)
		return x;
	else
		return 1.0;
}

double EuropeanOption::CallPrice() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(U/K)+(b+(sig*sig)*0.5)*T)/tmp;
	double d2 = d1 - tmp;

	return (U * exp((b-r)*T)*N(d1)) - (K*exp(-r*T)*N(d2)); // N is the cumulative distribution function of standard normal distribution

}

double EuropeanOption::PutPrice() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(U/K)+(b+(sig*sig)*0.5)*T)/tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)*N(-d2)) - (U*exp((b-r)*T)*N(-d1));
}

double EuropeanOption::CallDelta() const
{
	double tmp = sig * sqrt(T);
	
	double d1 = (log(U/K)+(b+(sig*sig)*0.5)*T)/tmp;

	return exp((b-r)*T)*N(d1);
}

double EuropeanOption::PutDelta() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(U/K) + (b+(sig*sig)*0.5)*T)/tmp;

	return exp((b-r)*T)*(N(d1) - 1.0);
}

void EuropeanOption::init()
{ // Initialize all default values

	// Default values
	r = 0.08;
	sig = 0.30;
	K = 65.0;
	T = 0.25;		
	U = 60.0;		// U == stock in this case
	b = r;			// Black and Scholes stock option model (1973)
	optType = "C";	// European Call Option (default type)

}

void EuropeanOption::copy(const EuropeanOption& o2)
{
	r = o2.r;
	sig = o2.sig;
	K = o2.K;
	T = o2.T;
	U = o2.U;
	b = o2.b;

	optType = o2.optType;
}

EuropeanOption::EuropeanOption()
{
	init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{
	copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType)
{
	init();
	optType = optionType;

	if(optType == "c")
		optType = "C";
}

EuropeanOption::~EuropeanOption()
{
	// Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt2)
{
	// Assignment operator (deep copy)

	if(this == &opt2) return *this;

	copy(opt2);

	return *this;
}

// Functions that calculate option price and sensitivity
double EuropeanOption::Price() const
{
	if(optType == "C")
	{
		return CallPrice();
	}
	else
		return PutPrice();
}

double EuropeanOption::Delta() const
{
	if(optType == "C")
		return CallDelta();
	else
		return PutDelta();
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if(optType == "C")
		optType = "P";
	else
		optType = "C";

}