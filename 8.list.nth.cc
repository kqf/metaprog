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

template <typename LST, int N>
struct Nth
{
    typedef typename LST::Tail Tail;
    typedef typename Nth < Tail, N - 1 >::result result;
};

template <typename LST>
struct Nth<LST, 0>
{
    typedef typename LST::Head result;
};

int main(int argc, char const * argv[])
{
    typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
    // TODO: Check this one
    typedef Nth< OneTwoThree, 1 > First;
    std::cout << "First Element" << First::result << std::endl;
    return 0;
}