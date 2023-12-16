#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer &serializer);
};