// TestPoint.cpp
//
// Constant objects testing
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
	void init(double xs, double ys);

	double x;
	double y;

public:

	Point();
	Point(double xs, double ys);
	Point(const Point& source);
	virtual ~Point();

	double X() const;
}