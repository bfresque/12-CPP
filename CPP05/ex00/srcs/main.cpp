/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/20 10:42:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main (void)
{
	try {
		std::cout << GREEN << "~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		Bureaucrat bureaucratA("Tom", 149);
		std::cout << "A new employee has joined the company :" << std::endl;
		std::cout << bureaucratA << std::endl;
		
		Bureaucrat bureaucratB("Gaga", 2);
		std::cout << "\nA new employee has joined the company :" << std::endl;
		std::cout << bureaucratB << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " has been promoted!!" << std::endl;
		bureaucratA.incrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " has been promoted!!" << std::endl;
		bureaucratB.incrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made a mistake..." << std::endl;
		bureaucratA.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " made a mistake..." << std::endl;
		bureaucratB.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made 2 new mistakes..." << std::endl;
		bureaucratA.decrementGrade();
		bureaucratA.decrementGrade();
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}