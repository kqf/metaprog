#include<iostream>
using std::cout;
using std::endl;

struct THEN
{
	static int func()
	{
		return 42;
	}
};

struct ELSE
{
	static int func()
	{
		return 0;
	}
};


template< bool CONDITION_TYPE > struct selector
{
	typedef THEN SELECT_CLASS;
};

template<> struct selector < false >
{
	typedef ELSE SELECT_CLASS;
};


template< bool Condition, class THEN, class ELSE > struct IF
{
	typedef typename selector<Condition>::SELECT_CLASS RESULT;
};

int main(int argc, char * argv[])
{
	int result = IF< 4 == sizeof(int), THEN, ELSE >::RESULT::func();
	cout << " - returning: " << result;
}