#include <iostream>

class CorrectClass 
{
public:	
	int a;
	CorrectClass() : a(7) {}

private:
	static const int m = 7;        
};

class MultipleConstructor 
{
public:
	MultipleConstructor(): a(7), _b(5), hashAlgorithm("MD5"), _s("Constructor run") {}
	MultipleConstructor(int aVal) : a(aVal), _b(5), hashAlgorithm("MD5"), _s("Constructor run") {}
	MultipleConstructor(int a, int b) : a(a), _b(b), hashAlgorithm("MD5"), _s("Constructor run") {}
	int a, _b;

private:
	std::string hashAlgorithm;  
	std::string _s;                   
};

//need g++ 4.7 version
class MultiplesConstructor 
{
public:
	MultiplesConstructor(): _a(7), _b(5) {}
	MultiplesConstructor(int aVal) : _a(aVal) {}
	MultiplesConstructor(int a, int b) : _a(a), _b(b) {}
	int _a, _b;

private:
	std::string _hashAlgorithm{"MD5"};  
	std::string _s{"Constructor run"};                  
};

class Aa {
	public:
		Aa() {}
		Aa(int aVal) : a(aVal) {}
		Aa(int a, int b) : a(a), b(b) {}
		int a = 7;
		int b = 5;	
};
