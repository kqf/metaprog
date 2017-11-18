struct NIL
{
	typedef NIL head;
	typedef NIL tail;
};

template < class H, class T = NIL> struct Lst
{
    typedef H head;
    typedef T tail;
};


template <class Elm, class LST> struct _Append
{
    typedef typename LST::Head Head;
    typedef typename LST::Tail Tail;

    typedef typename _Append<Elm, Tail>::result Next;
    typedef Lst<Head, Next> result;
};

template <typename Elm, typename Lst = NIL> struct Append
{
    typedef typename _Append<Elm, Lst>::result result;
};

template <class Elm> struct Append <Elm, NIL>
{
    typedef Lst<Elm> result;
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}