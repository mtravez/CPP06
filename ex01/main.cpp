#include "Serializer.hpp"

int main(void)
{
	Data hello("hello");
	hello.printContent();
	uintptr_t serialhello = Serializer::serialize(&hello);
	std::cout << serialhello << std::endl;
	Data *desirialhello = Serializer::deserialize(serialhello);
	desirialhello->printContent();
}