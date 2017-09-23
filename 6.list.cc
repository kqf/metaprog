template <int N> struct Int
{
	static const int value = N;
};


struct NIL
{
	typedef NIL Head;
	typedef NIL Tail;
};

template <typename H, typename T = NIL> struct Lst
{
	typedef H Head;
	typedef T Tail;
};


int main(int argc, char const *argv[])
{
	typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
	return 0;
}