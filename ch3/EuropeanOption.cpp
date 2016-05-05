// EuropeanOption.cpp
//
// Author: Daniel Duffy
//
// Black–Scholes model
//
// (C) Shujie CHEN @2016
//	


#include "EuropeanOption.hpp"	// Declarations of functions
#include <math.h>				// For mathematical functions, exp()

// Kernel Functions
double N(double x) const
{
	if(x < 0)
		return 0;
	else if(x > 0 && x < 1)
		return x;
	else
		return 1;
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
	
}

