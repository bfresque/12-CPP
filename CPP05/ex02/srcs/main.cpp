/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 09:44:13 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>


int main(void)
{
	std::cout << "~~~~~ ShrubberyCreationForm ~~~~~" << std::endl;
	std::cout << "Required grades: sign 145, exec 137" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat Bob("Bob", 1);
	Bureaucrat Jane("Jane", 140);
	Bureaucrat John("John", 150);

	ShrubberyCreationForm tree("tree");
	ShrubberyCreationForm forest("forest");

	std::cout << std::endl;

	try
	{
		std::cout << Bob << std::endl;
		std::cout << tree << std::endl;
		tree.execute(Bob);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << John << std::endl;
		std::cout << tree << std::endl;
		tree.beSigned(John);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Jane << std::endl;
		std::cout << tree << std::endl;
		tree.beSigned(Jane);
		Jane.executeForm(tree);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Bob << std::endl;
		tree.execute(Bob);
		forest.beSigned(Bob);
		Bob.executeForm(forest);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "~~~~~ RobotomyRequestForm ~~~~~" << std::endl;
	std::cout << "Required grades: sign 72, exec 45" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat Tia("Tia", 1);
	Bureaucrat Leo("Leo", 70);
	Bureaucrat Max("Max", 100);

	RobotomyRequestForm b("Oscar");
	RobotomyRequestForm b2("Robert");

	try
	{
		std::cout << Tia << std::endl;
		std::cout << b << std::endl;
		b.execute(Tia);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Max << std::endl;
		std::cout << b << std::endl;
		b.beSigned(Max);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Leo << std::endl;
		std::cout << b << std::endl;
		b.beSigned(Leo);
		Leo.executeForm(b);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Tia << std::endl;
		b.execute(Tia);
		b2.beSigned(Tia);
		Tia.executeForm(b2);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "~~~~~ PresidentialPardonForm ~~~~~" << std::endl;
	std::cout << "Required grades: sign 25, exec 5" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat Ava("Ava", 1);
	Bureaucrat Sam("Sam", 20);
	Bureaucrat Zoe("Zoe", 30);

	PresidentialPardonForm c("Luffy");
	PresidentialPardonForm c2("Peter");

	try
	{
		std::cout << c << std::endl;
		c.execute(Ava);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Zoe << std::endl;
		std::cout << c << std::endl;
		c.beSigned(Zoe);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Sam << std::endl;
		std::cout << c << std::endl;
		c.beSigned(Sam);
		Sam.executeForm(c);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << Ava << std::endl;
		c.execute(Ava);
		c2.beSigned(Ava);
		Ava.executeForm(c2);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
