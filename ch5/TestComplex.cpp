// TestComplex.cpp
//
// Operator overloading testing
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <string>
#include <complex>
#include <stdio.h>

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
	double getReal() const;
	double getImag() const;

};

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

int main()
{
	complex<long> comx1(32,45);
	complex<float> comx2(32.5,45.5);

	cout << "Real of comx1:" << comx1.real() << "::::Imaginary of comx1:" << comx1.imag() << endl;
	cout << "Real of comx2:" << comx2.real() << "::::Imaginary of comx2:" << comx2.imag() << endl;
	
	Complex z1(-23.0, 5.3);
	Complex z2(2.0, 3.0);
	Complex z3 = z1.add(z2);
	Complex z4 = z1 + z2;

	cout << "Real of z3:" << z3.getReal() << "::::Imaginary of z3:" << z3.getImag() << endl;
	cout << "Real of z4:" << z4.getReal() << "::::Imaginary of z4:" << z4.getImag() << endl;

	return 0;
}