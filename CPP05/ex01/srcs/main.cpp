/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/21 14:16:31 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

#include <iostream>

int main(void)
{
	std::cout << GREEN << "~~~ Welcome to the company! ~~~\n" << RESET << std::endl;
	try
	{
		std::cout << "A new employee has joined the company: " << std::endl;
		Bureaucrat bureaucratBob("Bob", 150);

		std::cout << "Another new employee has joined the company: " << std::endl;
		Bureaucrat bureaucratTia("Tia", 6);
		Form taxReturn("Tax Return", 150, 1500);
		Form topSecret("Top Secret", 5, 5);
		std::cout << std::endl;
		std::cout << bureaucratBob.getName() << " tries to sign " << taxReturn.getName() << std::endl;
		bureaucratBob.signForm(taxReturn);
		
		std::cout << std::endl;
		std::cout << bureaucratBob.getName() << " tries to sign " << topSecret.getName() << std::endl;
		bureaucratBob.signForm(topSecret);

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " is promoted!" << std::endl;
		bureaucratTia.incrementGrade();
		std::cout << bureaucratTia << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " tries to sign " << topSecret.getName() << std::endl;
		bureaucratTia.signForm(topSecret);

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " made a mistake..." << std::endl;
		bureaucratTia.decrementGrade();
		std::cout << bureaucratTia << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " tries to sign " << topSecret.getName() << std::endl;
		bureaucratTia.signForm(topSecret);
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}
	return (0);
}
