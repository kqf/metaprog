#include "iostream"
using std::cout;
using std::endl;

template<int i> class LOOP
{
public:
    static inline void evaluate()
    {
        cout << "Prefix  = " << i << " ";
        LOOP < i - 1 >::evaluate();
        cout << "Postfix = " << i << " ";
    }
};

template<> class LOOP <0>
{
public:
    static inline void evaluate()
    {
        cout << "Prefix  = " << 0;
        cout << "\n";
        cout << "Postfix = " << 0 << " ";
    }
};

int main()
{
    LOOP<9>::evaluate();
    cout << endl;
}