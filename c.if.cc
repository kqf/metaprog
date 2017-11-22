#include "iostream"
using std::cout;
using std::endl;

template <bool Condition, typename True, typename False> class if_;

template <typename True, typename False> struct if_<true, True, False>
{
	typedef True result;
};

template <typename True, typename False> struct if_<false, True, False>
{
	typedef False result;
};

int main()
{
	typename if_<true, int, void *>::result number(3);
	typename if_<false, int, void *>::result pointer(&number);
	typedef typename if_ < (sizeof(void *) > sizeof(int)), float, int >::result integral_ptr_t;
}