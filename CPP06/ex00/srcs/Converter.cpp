/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:57:55 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/29 10:03:07 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Converter.hpp"

Converter::Converter() {}

Converter::Converter(const Converter &other)
{
	(void)other;
}

Converter::~Converter() {}

Converter &Converter::operator=(const Converter &other)
{
	(void)other;
	return (*this);
}

bool	Converter::isChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (input[0] >= '0' && input[0] <= '9')
		return (false);
	if (input[0] >= 32 && input[0] < 127)
		return (true);
	return (false);
}

bool	Converter::isInt(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && input[i] == '-') // tester input[0] ??
			continue;
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	Converter::isFloat(const std::string &input)
{
	if (input[input.length() - 1] != 'f')
		return (false);
	if (input.find_first_of('.') != input.find_last_of('.') || input.find('.') == std::string::npos)
		return (false);
	for (size_t i = 0; (i < input.length() - 1); i++)
	{
		if (i == 0 && input[i] == '-')
			continue;
		if (input[i] == '.')
			continue;
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	Converter::isDouble(const std::string &input)
{
	if (input.find_first_of('.') != input.find_last_of('.') || input.find('.') == std::string::npos)
		return (false);
	for (size_t i = 0; (i < input.length() - 1); i++)
	{
		if (i == 0 && input[i] == '-')
			continue;
		if (input[i] == '.')
		{
			if (!isdigit(input[i + 1]) && !isdigit(input[i - 1]))
				return (false);
			continue;
		}
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	Converter::isPseudo(const std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" ||
		input == "-inf" || input == "+inf" || input == "nan")
			return (true);
	return (false);
}

void	Converter::printChar(char c, const std::string &input)
{
	if (verifOver(input, CHAR))
		std::cout << "Char: Overflow" << std::endl;
	else if (std::isprint(c))
		std::cout << "Char: '" << c << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
}

void	Converter::printInt(int i, const std::string &input)
{
	if (verifOver(input, INT))
		std::cout << "Int: Overflow" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
}

void	Converter::printFloat(float f, const std::string &input)
{
	if (verifOver(input, FLOAT))
		std::cout << "Float: Overflow" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
}

void	Converter::printDouble(double d, const std::string &input)
{
	if (verifOver(input, DOUBLE))
		std::cout << "Double: Overflow" << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}

void	Converter::printPseudo(const std::string &input)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;

	if (input.find("nan") != std::string::npos)
	{
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else
	{
		std::cout << "Float: " << input[0] << "inff" << std::endl;
		std::cout << "Double: " << input[0] << "inf" << std::endl;
	}
}

void	Converter::printInput(long double num, const std::string &input)
{
	printChar(static_cast<char>(num), input);
	printInt(static_cast<int>(num), input);
	printFloat(static_cast<float>(num), input);
	printDouble(static_cast<double>(num), input);
}

bool Converter::verifOver(const std::string &str, t_type type)
{
	long double num;

	num = std::strtold(str.c_str(), NULL);
	switch (type)
	{
		case CHAR:
			return (num < std::numeric_limits<char>::min() \
				|| num > std::numeric_limits<char>::max());
		case INT:
			return (num < std::numeric_limits<int>::min() \
				|| num > std::numeric_limits<int>::max());
		case FLOAT:
			return (num < -std::numeric_limits<float>::max()  \
				|| num > std::numeric_limits<float>::max());
		case DOUBLE:
			return (num < -std::numeric_limits<double>::max() \
				|| num > std::numeric_limits<double>::max());
		default:
			return (false);
	}
}

void Converter::convert(const std::string &input)
{
	std::cout << std::fixed << std::setprecision(1);
	if (isChar(input))
		printInput(input[0], input);
	else if (isInt(input))
		printInput(atoi(input.c_str()), input);
	else if (isFloat(input))
		printInput(std::strtof(input.c_str(), NULL), input);
	else if (isDouble(input))
		printInput(std::strtod(input.c_str(), NULL), input);
	else if (isPseudo(input))
		printPseudo(input);
	else
		std::cerr << "Error: Invalid type." << std::endl;
}
