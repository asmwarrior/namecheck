namespace mytest
{
	int variable = 1;
}

namespace MytesT
{
	int variable = 1;
}

namespace Mytest2
{
	int variable = 1;
}

namespace NSMyTest
{
	namespace NSTest1t
	{
		namespace NSTest2t
		{
			int i = 1;
		};
	};
};

namespace NSMyTest1t
{
	namespace test2t
	{
		const int length(1);
	};
};

namespace TEST
{
	bool free = true;
};

namespace NSMyTest2t
{
	bool isFree = false;

	namespace TEST1T
	{
		const int test(1);
	};
};