#include <iostream>
#include <string>
#include <complex>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include "Complex.hpp"

using namespace std;

Complex::Complex()
{
	// Nothing
}

Complex::Complex(double rel, double img)
{
	real = rel;
	imag = img;
}

Complex::~Complex()
{
	cout << "Complex is destructed." << endl;
}

double Complex::getReal() const
{
	return real;
}

double Complex::getImag() const
{
	return imag;
}

Complex Complex::add(const Complex& c2) const
{	// Add two complex numbers

	Complex result;
	result.real = real + c2.real;
	result.imag = imag + c2.imag;

	return result;
}

Complex Complex::operator + (const Complex& c2) const
{
	// Add two complex numbers
	Complex result;
	result.real = real + c2.real;
	result.imag = imag + c2.imag;

	return result;
}

Complex Complex::operator * (const Complex& c2) const
{
	// Times two complex numbers
	Complex result;
	result.real = real*c2.real - imag*c2.imag;
	result.imag = imag*c2.real + real*c2.imag;

	return result;
}

Complex Complex::operator * (const double& d2) const
{
	// Times the complex number with a double
	Complex result;
	result.real = real*d2;
	result.imag = imag*d2;

	return result;
}