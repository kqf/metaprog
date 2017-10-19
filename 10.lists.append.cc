template <class Elm, class LST>
struct Append
{
    typedef typename LST::Head Head;
    typedef typename LST::Tail Tail;

    typedef typename Append<Elm, Tail>::result Next;
    typedef Lst<Head, Next> result;
};

template <class Elm>
struct Append<Elm, NIL>
{
    typedef Lst<Elm> result;
};

template <typename Elm, typename Lst = NIL> 
struct Append
{
    typedef typename _Append<Elm, Lst>::result result;
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}