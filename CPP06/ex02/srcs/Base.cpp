/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:10:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/02 11:21:39 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base *generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) std::cout << "A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p); std::cout << "A\n";
	}
	catch (std::bad_cast&)
	{
		try
		{
			(void)dynamic_cast<B&>(p); std::cout << "B\n";
		}
		catch (std::bad_cast&)
		{
			std::cout << "C\n";
		}
	}
	return;
}
