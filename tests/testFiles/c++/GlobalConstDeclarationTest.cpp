const int CORRECT_GLOBAL(1);
const int Incorrect_global(1);
namespace prueba
{
	const int correct_ns(1);
	const int INCORRECT_NS(2);
};
void test()
{
	const int correct_func(2);
	const int INCORRECT_FUNC(2);
}

class Test
{
	const int _correctclass;
	const int INCORRECT_CLASS;
	Test() : _correctclass(1), INCORRECT_CLASS(1){};
};