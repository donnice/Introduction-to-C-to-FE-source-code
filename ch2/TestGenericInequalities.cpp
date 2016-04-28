#include <iostream>
using namespace std;

#include "GenericInequalities.cpp"

int main()
{
	//Prompt the user for input
	int d1,d2;
	cout << "Give the first Number:";
	cin >> d1;
	cout<<"Give the second number:";
	cin >> s2;

	char c;
	cout << "Max value is: "<<Max<int>(d1,d2)<<endl;
	cout << "Min value is: "<<Min<int>(d1,d2)<<endl;

	return 0;
}