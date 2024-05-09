/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:31:22 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/09 21:53:08 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER__HPP__
#define __SCALARCONVERTER__HPP__

#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
public:
	static void convert(std::string const &literal) throw();

private:
	ScalarConverter(void) throw();
	ScalarConverter(ScalarConverter const &src) throw();
	virtual ~ScalarConverter(void) throw();

	ScalarConverter &operator=(ScalarConverter const &rhs) throw();
};

#endif
