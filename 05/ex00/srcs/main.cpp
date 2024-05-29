/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 12:51:40 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main (void)
{
	try {
		std::cout << GREEN << "~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		Bureaucrat bureaucratBob("Bob", 149);
		std::cout << "A new employee has joined the company :" << std::endl;
		std::cout << bureaucratBob << std::endl;
		
		Bureaucrat bureaucratTia("Tia", 2);
		std::cout << "\nA new employee has joined the company :" << std::endl;
		std::cout << bureaucratTia << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratBob.getName() << " has been promoted!!" << std::endl;
		bureaucratBob.incrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " has been promoted!!" << std::endl;
		bureaucratTia.incrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratBob.getName() << " made a mistake..." << std::endl;
		bureaucratBob.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratTia.getName() << " made a mistake..." << std::endl;
		bureaucratTia.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratBob.getName() << " made 2 new mistakes..." << std::endl;
		bureaucratBob.decrementGrade();
		bureaucratBob.decrementGrade();
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}
	return (0);
}