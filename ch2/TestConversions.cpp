//TestConversions.cpp
//
//Simple stuff for converting built-in
//types to strings
//
//(C) Shujie CHEN @2016
//

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
     string getString(const T& value)
 {
 	stringstream s;
	s << value;
	return s.str();
 }

int main()
{
	int i = 10;
	long j = 1234567890;
	float f = 3.14f;
	double d = 2.712222222223;
	string myString = getString<int>(i);
	cout << myString << endl;
	myString = getString<long>(j);
	cout << myString << endl;
	myString = getString<float>(f);
	cout << myString << endl;
	myString = getString<double>(d);
	cout << myString << endl;
	return 0;
}