// Testrangle.cpp
//
// page 144 Good and bad rectangles using inherent
//
// (C) Shujie CHEN @2016
//

#include "rectangle.cpp"

#include <iostream>
using namespace std;

int main()
{
	cout << "Bad square:" << endl;
	BadSquare bs;
	bs.print();

	bs.setHeight(2.0);
	bs.print();

	cout << "Good square: " << endl;
	GoodSquare gs;
	gs.print();

	gs.setSize(2.0);
	gs.print();

	return 0;
}