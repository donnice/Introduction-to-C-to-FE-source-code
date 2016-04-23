//Inequalities.cpp
//(C) Shujie CHEN 2016

#include "Inequalities.hpp"
/////////////Useful functions////////////

double Max(double x, double y)
{
	if(x > y)
		return x;
	return y;
}

double Min(double x, double y)
{
	if(x < y)
		return x;
	return y;
}

double Max(double x, double y, double z){
	return x>y?(x>z?x:z):(y>z?y:z);
}

double Min(double x, double y, double z){
	return Min(Min(x,y),z);
}