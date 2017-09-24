#include <iostream>

template <int N>
struct Int
{
	static const int value = N;
};


struct NIL
{
	typedef NIL Head;
	typedef NIL Tail;
};

template <typename H, typename T = NIL>
struct Lst
{
	typedef H Head;
	typedef T Tail;
};


template <typename LST>
struct Length
{
	static const unsigned int result = 1 + Length< typename LST::Tail >::result;
};

template <>
struct Length<NIL>
{
	static const unsigned int result = 0;
};


int main(int argc, char const * argv[])
{
	typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
	typedef Length<OneTwoThree> OneTwoThreeLength;
	std::cout << "The length of the list is " << OneTwoThreeLength::result << std::endl;

	return 0;
}