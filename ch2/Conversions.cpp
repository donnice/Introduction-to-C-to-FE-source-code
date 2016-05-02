//Conversions.hpp
//
//template of getString()
//
//(C) Shuije CHEN @2016

#ifndef Conversions_HPP
#define Conversions_HPP

#include <string>
using namespace std;
#include <stddef.h>
#include "Conversions.hpp"

/////////////////Useful functions///////////////////
//getString()

std::string getString(long j)
{
	char str[200];
	sprintf(str, "%d",j);
	std::string result(str);
	return result;
}

std::string getString(int j)
{
	char str[200];
	sprintf(str, "%d",j);
	std::string result(str);
	return result;
}

std::string getString(size_t j)
{
	char str[200];
	sprintf(str, "%d",j);
	std::string result(str);
	return result;
}

////////////////////////////////////////////
#endif