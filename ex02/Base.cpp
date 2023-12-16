#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout << "Called destructor\n";
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "The type is A\n";
	if (dynamic_cast<B *>(p))
		std::cout << "The type is B\n";
	if (dynamic_cast<C *>(p))
		std::cout << "The type is C\n";
}

void identify(Base &p)
{
	try {
		A temp = dynamic_cast<A &>(p);
		std::cout << "Identified A\n";
	}
	catch (std::exception &e)
	{
		try {
			B temp = dynamic_cast<B &>(p);
			std::cout << "Identified B\n";
		}
		catch (std::exception &e)
		{
			try {
				C temp = dynamic_cast<C &>(p);
				std::cout << "Identified C\n";
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
}

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int number = rand() % 3;

	if (!number)
	{
		std::cout << "Generated A\n";
		return (new A());
	}
	if (number == 1)
	{
		std::cout << "Generated B\n";
		return (new B());
	}
	std::cout << "Generated C\n";
	return (new C());
}
