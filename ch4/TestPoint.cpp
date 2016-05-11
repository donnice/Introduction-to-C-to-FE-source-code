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

	Point();						// Default constructor
	Point(double xs, double ys);	// Constructor with coordinates
	Point(const Point& source);		// Copy of constructor
	virtual ~Point();				// Destructor

	double X() const;				// return X
	double Y() const;				// return Y
	Point MidPoint(const Point& p2) const;

	void X(double NewX);			// Set X
	void Y(double NewY);			// Set Y
};

Point::Point()
{
	
}

Point::Point(double xs, double ys)
{
	x = xs;
	y = ys;
}

Point::~Point()
{
	cout << "Point is destructed" << endl;
}

Point Point::MidPoint(const Point& p2) const
{
	return Point((x+p2.x)*0.5,(y+p2.y)*0.5);
}

double Point::X() const
{
	return x;
}

double Point::Y() const
{
	return y;
}

void Point::X(double NewX)
{
	x = NewX;
} 

void Point::Y(double NewY)
{
	y = NewY;
}

int main()
{
	Point p1(1.0,3.14);

	cout << "First coordinate: " << p1.X() << endl;
	cout << "Second coordinate: " << p1.Y() << endl;

	p1.X(2.0);
	p1.Y(5.0);

	cout << "First coordinate: " << p1.X() << endl;
	cout << "Second coordinate: " << p1.Y() << endl;	

	Point pL(0.0,0.0);
	Point pU(1.0,1.0);
	Point pM = pL.MidPoint(pU);
	cout << "MidPoint: " << pM.X() << "," <<pM.Y() << endl;

	return 0;
}