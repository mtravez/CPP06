#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	std::string hi = "nanffjskf";
	if (argc != 2)
		return 1;
//	ScalarConverter::floatToOther(15.0);
//	std::cout << std::stod("nanf", 0) << std::endl;
//	std::cout << hi.find('.') << std::endl;
	ScalarConverter::convert(argv[1]);
//	std::cout << &argv[1][strlen(argv[1]) - 3] << std::endl;
	return (0);
}