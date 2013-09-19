#include <map>
#include <string>

template <typename T>
using dictionary = std::map< std::string, T >;

void lala()
{
dictionary<int> ints;
ints[ "one" ] = 1;
ints[ "two" ] = 2;
}
