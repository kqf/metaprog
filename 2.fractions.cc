#include <iostream>

template <int N, int D> struct Frak
{
    static const long Num = N;
    static const long Den = D;
};

template <int N, typename F> struct ScalarMultiplication
{
    typedef Frak<N * F::Num, N * F::Den> result;
};

int main()
{
    typedef Frak< 2, 3 > Two_Thirds;
    typedef ScalarMultiplication< 2, Two_Thirds >::result Four_Sixths;
    std::cout << Four_Sixths::Num << "/" << Four_Sixths::Den << "\n";
}