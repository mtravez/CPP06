#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <stdint.h>

class ScalarConverter
{
public:
	static void intToOther(int nr);
	static void charToOther(char c);
	static void floatToOther(float nr);
	static void doubleToOther(double nr);
	static void convert(char *nbr);

private:
	ScalarConverter();
	static void	printMessage(int i, char c, float f, double d, bool possibleInt, bool possibleChar);
	static bool isDouble(char *string);
	static bool isFloat(char *string);
	static bool isInt(char *string);
	static bool isChar(char *string);
};