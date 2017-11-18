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
 

// Helper: Will fail to compile if the assert is false
class Assertion {};
template <bool cond, class T = Assertion> struct Assert
{
    typedef typename T::fail check;
};
template <> struct Assert<true>
{
    typedef void check;
};

/******************************************************/

template <typename Elm, typename LST> struct _Position
{
    typedef typename LST::Head Head;
    typedef typename LST::Tail Tail;

    static const bool found = Eq<Elm, Head>::result;
    static const int result = (found) ? 0 : 1 + _Position<Elm, Tail>::result;
};

// The compiler will try to expand the position check
// after NIL has been reached if this isn't here
template <typename Elm> struct _Position<Elm, NIL>
{
    static const int result = 0;
};

template <typename Elm, typename LST> struct Position
{
    typedef typename Assert<Includes< Elm, LST >::result>::check include;
    static const int result = _Position<Elm, LST>::result;
};


int main()
{
}