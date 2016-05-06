// EuropeanOption.hpp
//
// Author: Daniel Duffy
//
// (C) Shujie CHEN @2016
//	

#include <string>
using namespace std;

class EuropeanOption
{
private:

	void init();		// Initialise all default values
	void copy(const EuropeanOption& o2);
	//"Kernel" functions for option calculations
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;

public:
	// Public member data for convenience
	double r;			// Interest rate
	double sig;			// Volatility
	double K;			// Strike price
	double T;			// Expiry date
	double U;			// Current underlying price
	double b;			// Cost of carry
	string optType;

public:
	// Constructors
	EuropeanOption(); // Default call option
	EuropeanOption(const EuropeanOption& option2); // Copy constructor
	EuropeanOption(const string& optionType); // Create option type

	// Destructor
	virtual ~EuropeanOption();

	// Assignment operator
	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;

	// Modifier functions
	void toggle();
};