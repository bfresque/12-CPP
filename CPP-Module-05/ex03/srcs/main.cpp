/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:22 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 16:57:57 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat bureaucratTia("Tia", 6);
	Bureaucrat bureaucratBob("Bob", 150);
	AForm* form;
	AForm* formP;
	AForm* formR;
	AForm* formS;

	std::cout << std::endl;
	formS = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
	std::cout << *formS <<  std::endl;
	std::cout << std::endl;
	formR = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	std::cout << *formR <<  std::endl;
	std::cout << std::endl;
	formP = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
	std::cout << *formP <<  std::endl;
	std::cout << std::endl;
	form = someRandomIntern.makeForm("UnknownForm", "Target");

	std::cout << std::endl;
	bureaucratTia.signAForm(*formS);
	std::cout << *formS <<  std::endl;
	bureaucratTia.signAForm(*formS);

	std::cout << std::endl;
	bureaucratBob.signAForm(*formR);

	std::cout << std::endl;
	delete formP;
	delete formR;
	delete formS;
	return (0);
}
