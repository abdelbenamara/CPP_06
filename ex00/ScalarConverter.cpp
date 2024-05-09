/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:38:02 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/09 22:06:06 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) throw() { return; }

ScalarConverter::ScalarConverter(ScalarConverter const &src) throw() { return; }

ScalarConverter::~ScalarConverter(void) throw() { return; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) throw() { return (*this); }

void ScalarConverter::convert(std::string const &literal) throw()
{
	bool isImpossible = false;
	bool isChar = true;
	bool isFinite = true;
	char c;
	int i;
	float f;
	double d;

	try
	{
		d = std::stod(literal);
	}
	catch (std::exception const &e)
	{
		if (literal.length() > 1)
			isChar = false;
		
		if (!isChar)
			isImpossible = true;

		if (isChar)
			d = static_cast<double>(literal.at(0));
	}

	if (isImpossible)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;

		return;
	}

	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	isFinite = (d == std::numeric_limits<double>::quiet_NaN() || d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity());

	std::cout << "char: ";
	
	if (!isFinite)
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "non displayable";
	else
		std::cout << c;

	std::cout << std::endl;

	std::cout << "int: ";

	if (d < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < d)
		std::cout << "impossible";
	else
		std::cout << i;

	return;
}
