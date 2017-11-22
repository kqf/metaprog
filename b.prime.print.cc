#include <iostream>

template <int p, int i> class IsPrime
{
public:
	enum { prim = ( (p % i) && IsPrime < p, i - 1 >::prim ) };
};

template <int p> class IsPrime <p, 1>
{
public:
	enum { prim = 1 };
};

// primary template for loop to print prime numbers
template <int i> class PrimePrint
{
public:
	PrimePrint < i - 1 > a;
	enum { prim = IsPrime < i, i - 1 >::prim };
	void eval()
	{
		a.eval();
		if (prim)
			std::cout << "prime number:" << i << std::endl;
	}
};

// full specialization to end the loop
template<> class PrimePrint<1>
{
public:
	enum { prim = 0 };
	void eval() {}
};

int main()
{
	PrimePrint<18> a;
	a.eval();
}