/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:44:28 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 09:57:21 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string newForm, const std::string targetFrom)
{
	AForm *(*allForms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (newForm == forms[i])
		{
			std::cout << GREEN << "Intern creates " << newForm << " now" << RESET << std::endl;
			return (allForms[i](targetFrom));
		}
	}

	std::cout << RED <<"Intern can not create a form called " << newForm << RESET << std::endl;
	return (NULL);
}
