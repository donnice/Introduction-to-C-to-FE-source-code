// PayoffStrategy.hpp
//
// Lightweight classes for payoff functions. P140
//
// (C) Shujie CHEN @2016

class PayoffStrategy
{
public:
		virtual double price(double S) const = 0;
};

class CallStrategy : public PayoffStrategy
{
private:
		double K;
public:
		CallStrategy(double strike){ K = strike;}
		double price(double S) const
		{
			if(S > K)
				return (S-K);
			
			return 0.0;

			// or max (S-K,0)
		}
};

class BullSpreadStrategy: public PayoffStrategy
{
private:

		double K1;
		double K2;
public:
		BullSpreadStrategy(double strike1, double strike2)
		{
			K1 = strike1;
			K2 = strike2;
		}

		double price(double S) const
		{
			if (S >= K2)
				return K2 - K1;
			if (S <= K1)
				return 0.0;

			// In the interval [K1, K2]
			return S - K1;
		}
};