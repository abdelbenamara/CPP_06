/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:23:36 by abenamar          #+#    #+#             */
/*   Updated: 2024/05/11 18:45:23 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int const n = std::rand() % 3;

	if (n == 1)
		return (new A());
	else if (n == 2)
		return (new B());

	return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "\033[1;32mInfo: \033[0;34midentify(Base *p): \033[0mA" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\033[1;32mInfo: \033[0;34midentify(Base *p): \033[0mB" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\033[1;32mInfo: \033[0;34midentify(Base *p): \033[0mC" << std::endl;
	else
		std::cerr << "\033[1;31mError: \033[0;34midentify(Base *p): \033[0mNULL" << std::endl;

	return;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "\033[1;32mInfo: \033[0;34midentify(Base &p): \033[0mA" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "\033[1;32mInfo: \033[0;34midentify(Base &p): \033[0mB" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "\033[1;32mInfo: \033[0;34midentify(Base &p): \033[0mC" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << "\033[1;31mError: \033[0;34midentify(Base &p): \033[0m" << e.what() << std::endl;
			}
		}
	}

	return;
}

int main(void)
{
	Base *random;
	Base base;
	A a;
	B b;
	C c;

	std::srand(std::time(NULL));

	random = ::generate();

	::identify(random);
	::identify(*random);
	::identify(&base);
	::identify(&a);
	::identify(&b);
	::identify(&c);
	::identify(base);
	::identify(a);
	::identify(b);
	::identify(c);

	delete random;

	return (0);
}
