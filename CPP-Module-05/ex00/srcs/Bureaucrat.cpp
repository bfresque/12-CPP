/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:19 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 12:47:22 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultB"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "Bureaucrat Copy Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called for : " << WHITE << getName() << RESET << std::endl;
	return;
}

/***************************************************************************************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) // Copy Assignement
{
	std::cout << "Bureaucrat Copy Assignement called" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

/***************************************************************************************/

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

/***************************************************************************************/

int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return(this->_name);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Bureaucrat name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
	return (os);
}

