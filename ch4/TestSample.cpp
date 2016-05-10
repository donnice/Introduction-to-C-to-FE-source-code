// TestSample.cpp
//
// Sample class, main, etc
//
// (C)Shujie CHEN @2016

#include <iostream>
#include <string>

using namespace std;

class SampleClass
{
public:
	// data created at compile time
	double contents[1000];

public:
	SampleClass(double d)
	{
		for(int i = 0; i < 1000; i++)
		{
			contents[i] = d;
		}
	}

	virtual ~SampleClass()
	{
		cout << "SampleClass instance being deleted\n";
	}
};

double Sum(SampleClass myClass)
{
	double result = myClass.contents[0];
	for(int i = 1; i < 1000; i++)
	{
		result += myClass.contents[i];
	}
	return result;
};

int main()
{
	SampleClass sc(1.0);
	double sum = Sum(sc);

	return 0;
}