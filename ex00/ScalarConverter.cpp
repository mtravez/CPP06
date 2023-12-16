#include "ScalarConverter.hpp"
#include <float.h>
#include <limits>
#include "errno.h"

void ScalarConverter::intToOther(int nr)
{
	char c;
	float f;
	double d;
	bool possible = true;

	if (nr > 32 && nr < 126)
		c = nr;
	else
	{
		if (nr < -128 || nr > 127)
			possible = false;
		c = 0;
	}

	f = static_cast<float>(nr);
	d = static_cast<double>(nr);
	printMessage(nr, c, f, d, true, possible);
}

void ScalarConverter::charToOther(char c)
{
	printMessage((int)c, c, static_cast<float>(c), (double)c, true, true);
}

void ScalarConverter::floatToOther(float nr)
{
	int i = 0;
	char c = 0;
	double d;
	bool possibleInt = true;
	bool possibleChar = true;

	if (std::isnan(nr) || std::isinf(nr))
	{
		possibleInt = false;
		possibleChar = false;
	}
	else
	{
		if (nr > static_cast<float>(INT32_MAX) || nr < static_cast<float>(INT32_MIN))
			possibleInt = false;
		i = static_cast<int>(nr);
		if (i > 32 && i < 126)
			c = static_cast<char>(nr);
		else if (nr < -128 || nr > 127)
			possibleChar = false;
	}

	d = static_cast<double>(nr);
	printMessage(i, c, nr, d, possibleInt, possibleChar);
}

void ScalarConverter::doubleToOther(double nr)
{
	int i = 0;
	char c = 0;
	float f;
	bool possibleInt = true;
	bool possibleChar = true;

	if (std::isnan(nr) || std::isinf(nr))
	{
		possibleInt = false;
		possibleChar = false;
	}
	else
	{
		if (nr > static_cast<double>(INT32_MAX) || nr < static_cast<double>(INT32_MIN))
			possibleInt = false;
		i = static_cast<int>(nr);
		if (i > 32 && i < 126)
			c = static_cast<char>(nr);
		else if (nr < -128 || nr > 127)
			possibleChar = false;
	}
	f = static_cast<float>(nr);
	printMessage(i, c, f, nr, possibleInt, possibleChar);

}

void ScalarConverter::printMessage(int i, char c, float f, double d, bool possibleInt, bool possibleChar)
{
	if (!possibleChar)
		std::cout << "char: impossible\n";
	else
	{
		if (!c)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << c << "'\n";
	}
	if (!possibleInt)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f;
	if (f == i && ((f < 1000000 && f >= 0) || (f > -1000000 && f <= 0)))
		std::cout << ".0";
	std::cout << "f\n";
	std::cout << "double: " << d;
	if (d == i && ((d < 1000000 && d >= 0) || (d > -1000000 && d <= 0)))
		std::cout << ".0";
	std::cout << std::endl;
}

bool ScalarConverter::isDouble(char *string)
{
	bool isIt = false;
	
	if (strchr(string, '.') && strchr(string, '.') == strrchr(string, '.'))
	{
		isIt = true;
		std::strtod(string, 0);
		if (errno == ERANGE)
			isIt = false;
	}
	if (string[strlen(string) - 1] == 'f')
		isIt = false;
	else if (strcmp(string, "nan") == 0)
		isIt = true;
	if (!strcmp(string, "+inf") || !strcmp(string, "-inf") || !strcmp(string, "inf"))
		isIt = true;
	return isIt;
}

bool ScalarConverter::isFloat(char *string)
{
	bool isIt = false;
	if (strchr(string, '.') && string[strlen(string) - 1] == 'f')
	{
		isIt = true;
		std::cout << (long long) atol(string) << "\n";
		if (strtod(string, 0) > MAXFLOAT || strtod(string, 0) < -MAXFLOAT)
			isIt = false;
	}
	if (strcmp(string, "nanf") == 0)
		isIt = true;
	if (!strcmp(string, "+inff") || !strcmp(string, "-inff") || !strcmp(string, "inff"))
		isIt = true;
	return isIt;
}

bool ScalarConverter::isChar(char *string)
{
//	std::cout << strlen(string) << std::endl;
	if (strlen(string) == 1 && !isdigit(string[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(char *string)
{
	int i = -1;
	if (!isdigit(string[0]) && (string[0] != '-' && string[0] != '+'))
		return false;
	else
		i++;
	while (string[++i])
		if (!isdigit(string[i]))
			return false;
	if (atol(string) > INT32_MAX || atol(string) < INT32_MIN)
		return false;
	return true;
}

void ScalarConverter::convert(char *nbr)
{
	if (isInt(nbr))
	{
		try {
			intToOther(atoi(nbr));
			return;
		}
		catch (std::exception &e)
		{
			std::cerr << "Wrong input\n";
			return;
		}
	}
	if (isDouble(nbr))
	{
		try {
			doubleToOther(static_cast<double>(atof(nbr)));
			return;
		}
		catch (std::exception &e)
		{
			std::cerr << "Wrong input\n";
			return;
		}
	}
	if (isFloat(nbr))
	{
		try {
			floatToOther(atof(nbr));
			return;
		}
		catch (std::exception &e)
		{
			std::cerr << "Wrong input\n";
			return;
		}
	}
	if (isChar(nbr))
	{
		try
		{
			charToOther(nbr[0]);
			return;
		}
		catch (std::exception &e)
		{
			std::cerr << "Wrong input\n";
			return;
		}
	}
	std::cerr << "Wrong input\n";
	return;
}