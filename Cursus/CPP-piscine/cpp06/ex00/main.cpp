/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:03:07 by gfaviere          #+#    #+#             */
/*   Updated: 2022/02/19 11:18:37 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <climits>

static void convertFromDouble(double const &d)
{
	unsigned char c = static_cast<unsigned char>(d);
	long int i = static_cast<long int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout<< "int: " << i << std::endl ;
	std::cout
	<< "float: " << f << std::endl
	<< "double: " << d << std::endl;
}

static void convertFromFloat(float const &f)
{
	unsigned char c = static_cast<unsigned char>(f);
	long int i = static_cast<long int>(f);
	double d = f;

	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << c << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout<< "int: " << i << std::endl ;
	std::cout
	<< "float: " << f << std::endl
	<< "double: " << d << std::endl;
}

static void convertFromInt(int const &i)
{
	unsigned char c = static_cast<unsigned char>(i);
	float f = i;
	double d = i;

	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << c << std::endl;
	std::cout
	<< "int: " << i << std::endl 
	<< "float: " << f << std::endl
	<< "double: " << d << std::endl;
		
}

static void convertFromChar(char const &c)
{
	int i = c;
	float f = c;
	double d = c;
	std::cout 
	<< "char: " << c << std::endl
	<< "int: " << i << std::endl
	<< "float: " << f << std::endl
	<< "double: " << d << std::endl;
}

static void executeConversion(std::string const &argument, int const &type)
{
	switch (type)
	{
	case 0:
		convertFromInt(std::stoi(argument));
		break;
	case 1:
		convertFromChar(argument[0]);
		break;
	case 2:
		convertFromFloat(std::stof(argument));
		break;
	case 3:
		convertFromDouble(std::stod(argument));
		break;
		
	default:
		std::cout << "Not a valid type." << std::endl;
		break;
	}
}

static bool isDouble(std::string const &argument)
{
	int dot = 0;

	if (!argument.compare("-inf") || !argument.compare("+inf") || !argument.compare("nan"))
		return (true);
	for (size_t i = 0; i < argument.length(); i++)
	{
		if ((argument[0] == '-' || argument[0] == '+') && i == 0)
			i++;
		if (!isdigit(argument[i]) && argument[i] != '.')
			return (false);
		if (argument[i] == '.')
			dot += 1;
	}
	if (dot != 1)
		return (false);
	try
	{
		std::stod(argument);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Number out of double limit. ";
		return (false);
	}
	return (true);
}

static bool isFloat(std::string const &argument)
{
	int dot = 0;
	int f = 0;
	int digits = 0;

	if (!argument.compare("-inff") || !argument.compare("+inff") || !argument.compare("nanf"))
		return (true);
	for (size_t i = 0; i < argument.length(); i++)
	{
		if ((argument[0] == '-' || argument[0] == '+') && i == 0)
			i++;
		if (!isdigit(argument[i]) && argument[i] != '.' && argument[i] != 'f')
			return (false);
		if (argument[i] == '.')
			dot += 1;
		if (argument[i] == 'f')
			f += 1;
		if (isdigit(argument[i]))
			digits += 1;
	}
	if (dot != 1 || f != 1 || argument[argument.length() - 1] != 'f' || !digits)
		return (false);
	try
	{
		std::stof(argument);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Number out of float limit. ";
		return (false);
	}  
	return (true);
}

static bool isInt(std::string const &argument)
{
	for (size_t i = 0; i < argument.length(); i++)
	{
		if ((argument[0] == '-' || argument[0] == '+') && i == 0)
			i++;
		if (!isdigit(argument[i]))
			return (false);
	}
	try
	{
		std::stoi(argument);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Number out of int limit. ";
		return (false);
	}
		
	return (true);
}

static bool isChar(std::string const &argument)
{
	if (argument.length() == 1 && (argument[0] > 31 && argument[0] < 127))
		return (true);
	return (false);
}

static int getType(std::string const &argument)
{
	if (isInt(argument))
		return (0);
	if (isChar(argument))
		return (1);
	if (isFloat(argument))
		return (2);
	if (isDouble(argument))
		return (3);
	return (4);
}

static bool checkArgs(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (false);
	}
	std::string const str(argv[1]);
	if (str.empty())
	{
		std::cout << "Argument cant be empty" << std::endl;
		return (false);
	}
	if (str.length() == 1 && (str[0] < 32 || str[0] > 126))
	{
		std::cout << "Non displayable char passed as argument. Exiting" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (!checkArgs(argc, argv))
		return (0);

	std::string const arg(argv[1]);
	int type;

	type = getType(arg);
	executeConversion(arg, type); 
	return (1);
}