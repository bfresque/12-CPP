/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/17 15:41:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	Bureaucrat *Bob = new Bureaucrat("Bob", 2);
	std::cout << Bob;

	try
	{
		Bob->incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << YELLOW << "Incrementing grade of " << Bob->getName() << " failed: " << e.what() << RESET << std::endl;
		//Lili a dit cest mieux sur sortie err
	}
	std::cout << Bob;

	try
	{
		Bob->incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << YELLOW << "Incrementing grade of " << Bob->getName() << " failed: " << e.what() << RESET << std::endl;
	}
	std::cout << Bob;

	try
	{
		Bob->decrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << YELLOW << "Incrementing grade of " << Bob->getName() << " failed: " << e.what() << RESET << std::endl;
	}
	std::cout << Bob;

	delete Bob;
	return (0);
}

