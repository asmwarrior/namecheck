const int CORRECT_GLOBAL(1);
const int Incorrect_global(1);
namespace NSPrueba
{
	const int incorrectns(1);
	const int CORRECT_NS(2);
};
void test()
{
	const int correctfunc(2);
	const int INCORRECTFUNC(2);
}

class Test
{
	const int _correctclass;
	const int INCORRECT_CLASS;
	Test() : _correctclass(1), INCORRECT_CLASS(1){};
};