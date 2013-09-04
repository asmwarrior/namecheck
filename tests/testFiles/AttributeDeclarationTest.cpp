#include <string>

class Test1t
{
	public:		
//		Test1t();
//		~Test1t();
		void myMethod();

		int _lenth;
		bool _isFree;	

	protected:
		int _lengthOfSequence;

	private:
		int _lengthOfSequences;
		std::string _something;
		const std::string _name;
};

class Test2t
{
	public:		
		void myMethod();

		int _Lenth;
		bool _FREE;	
};

//Test1t::Test1t() : _name()
//{}
//Test1t::~Test1t() {}

void Test1t::myMethod()
{
	_lenth = _lengthOfSequences;		
}