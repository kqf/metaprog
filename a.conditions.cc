template< bool Condition, class THEN, class ELSE > struct IF
{
	template< bool Condition > struct selector
	{typedef THEN SELECT_CLASS;};

	struct selector< false >
	{typedef ELSE SELECT_CLASS;};

	typedef selector< Condition >::SELECT_CLASS RESULT;
};


struct THEN
{
	static int func()
	{
		cout << "Inside THEN";
		return 42;
	}
};

struct ELSE
{
	static int func()
	{
		cout << "Inside ELSE";
		return 0;
	}
};

int main(int argc, char * argv[])
{
	int result = IF< 4 == sizeof(int), THEN, ELSE >::RESULT::func();
	cout << " - returning: " << result;
}