template <class Elm, class LST> struct Includes
{
	typedef typename LST::Head Head;
	typedef typename LST::Tail Tail;

	static const bool found = (Elm == Head);
	static const bool found_tail = Includes<Elm, Tail>::result;
	static const bool result = found || found_tail;
};

template <class Elm> struct Includes <Elm, NIL>
{
	static const bool result = false;
};


int main(int argc, char const *argv[])
{
	
	return 0;
}