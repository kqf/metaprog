template <bool Condition, typename TrueResult, typename FalseResult>
class if_;

template <typename TrueResult, typename FalseResult>
struct if_<true, TrueResult, FalseResult>
{
	typedef TrueResult result;
};

template <typename TrueResult, typename FalseResult>
struct if_<false, TrueResult, FalseResult>
{
	typedef FalseResult result;
};

int main()
{
	typename if_<true, int, void *>::result number(3);
	typename if_<false, int, void *>::result pointer(&number);

	typedef typename if_ < (sizeof(void *) > sizeof(uint32_t)), uint64_t, uint32_t >::result
	integral_ptr_t;

	integral_ptr_t converted_pointer = reinterpret_cast<integral_ptr_t>(pointer);
}