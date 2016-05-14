// ComplexArray.hpp
//
// Simple Complex Array class.
//
// (C) Shujie CHEN @2016

#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>
#include <string>
#include <complex>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

class Complex
{
private:
	// Self constructor
	double real;
	double imag;

public:
	Complex();
	Complex(double rel, double img);
	virtual ~Complex();

	Complex add(const Complex& c2) const;
	Complex operator + (const Complex& c2) const;
	Complex operator * (const Complex& c2) const;
	Complex operator * (const double& d2) const;
	double getReal() const;
	double getImag() const;

	friend Complex exp(const Complex& c);				// Exponential
	//friend Complex cos(const Complex& c);				// Cosine function
	//friend Complex sin(const Complex& c);				// Sine function
	//friend Complex cosh(const Complex& c);			// Hyperbolic cosine
	//friend Complex sinh(const Complex& c);			// Hyperbolic sine

};

#endif