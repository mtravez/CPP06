#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <stdint.h>

struct Data{
public:
	Data();
	Data(Data &data);
	Data(std::string content);
	~Data();
	Data &operator=(Data &data);
	void printContent();
private:
	std::string content;
};