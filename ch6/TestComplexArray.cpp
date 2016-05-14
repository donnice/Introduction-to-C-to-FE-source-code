// TestComplexArray.cpp
//
// Introduce memory allocation and deallocation
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <stdio.h>
#include "Complex.hpp"

class ComplexArray
{
private:
	Complex* arr;
	int size;

public:
	ComplexArray(int size);
	ComplexArray(const ComplexArray& source);
	virtual ~ComplexArray();

	int MinIndex() const;
	int MaxIndex() const;

	// Operators
	const Complex& operator[](int index) const;
	Complex& operator[](int index);

	ComplexArray& operator = (const ComplexArray& source);
};

ComplexArray::ComplexArray(int siz)
{
	arr = new Complex[size];
	size = siz;
}

ComplexArray::ComplexArray(const ComplexArray& source)
{
	// Deep copy source
	size = source.size;
	arr = new Complex[size];
	for(int i = 0; i < size; i++)
		arr[i] = source.arr[i];
}

ComplexArray::~ComplexArray()
{
	delete[] arr;
}

int ComplexArray::MinIndex() const
{
	if(size >= 0)
		return 0;
	else
		return -1;
}

int ComplexArray::MaxIndex() const
{
	return size - 1;
}

Complex ComplexSum(const ComplexArray& carr, int n)
{	// Complex function of several complex variables

	Complex sum = carr[carr.MinIndex()];

	for(int j = carr.MinIndex()+1; j <= carr.MaxIndex(); j++)
	{
		sum += carr[j];
	}
	return sum;

}

int main()
{
	ComplexArray fixedArray(5);

	return 0;
}