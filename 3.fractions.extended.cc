#include <iostream>

template <int N, int D> struct Fraction
{
    static const long Num = N;
    static const long Den = D;
};

// Minimal common divisior
template <int X, int Y>   struct MCD
{
    static const long result = MCD < Y, X % Y >::result;
};

template <int X> struct MCD<X, 0>
{
    static const long result = X;
};

template <class F> struct Simplify
{
    static const long mcd = MCD<F::Num, F::Den>::result;
    typedef Fraction < F::Num / mcd, F::Den / mcd > result;
};

int main()
{
    typedef Fraction< 4, 6 > Two_Thirds;
    typedef Simplify<Two_Thirds>::result Simplified_Value;

    std::cout << "Before: \n";
    std::cout << Two_Thirds::Num << "/" << Two_Thirds::Den << "\n";

    std::cout << "After: \n";
    std::cout << Simplified_Value::Num << "/" << Simplified_Value::Den << "\n";

    // Simplify again
    typedef Simplify<Two_Thirds>::result TwoTimesSimplified;
    std::cout << "Trying to simplify again: \n";
    std::cout << TwoTimesSimplified::Num << "/" << TwoTimesSimplified::Den << "\n";

}