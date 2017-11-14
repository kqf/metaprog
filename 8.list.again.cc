struct NIL
{
	typedef NIL head;
	typedef NIL tail;
};
template <class X, class Y> struct Eq
{
	static const bool result = false;
};

template <class X> struct Eq<X, X>
{
	static const bool result = true;
};

template <class Elm, class LST> struct Includes
{
	static const bool result = Eq< Elm,
		typename LST::Head>::result || Includes<Elm, typename LST::Tail>::result;
};
 
int main(int argc, char const *argv[])
{

	return 0;
}