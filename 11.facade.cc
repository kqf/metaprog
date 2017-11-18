#include <iostream>
using std::cout;

struct NIL
{
    typedef NIL head;
    typedef NIL tail;
};

template < class H, class T = NIL>
struct Lst
{
    typedef H head;
    typedef T tail;
};

template <class X, class Y> struct Eq
{
    static const bool result = false;
};

template <class X> struct Eq<X, X>
{
    static const bool result = true;
};

template <class Elm, class LST> struct Position
{
private:
    typedef typename LST::head H;
    typedef typename LST::tail T;
    static const bool found = Eq<H, Elm>::result;
public:
    static const int result = found ? 1 : 1 + Position<Elm, T>::result;
};

template <class Elm> struct Position<Elm, NIL>
{
    static const int result = 0;
};

class Facade
{
    typedef Lst<int, Lst<char, Lst<float> > > Lst;

public:
    template <class PK> int find(PK)
    {
        return Position< PK, Lst >::result;
    }
};

int main()
{
    Facade f;
    std::cout << f.find(1.0) << "\n";
    return 0;
}