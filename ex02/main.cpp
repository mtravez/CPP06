#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{
	Base *hello = generate();

	identify(hello);
	identify(*hello);
	delete(hello);
	return 0;
}