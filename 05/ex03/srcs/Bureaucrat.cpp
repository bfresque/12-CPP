/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:19 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 16:53:45 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultB"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) // Copy Assignement
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

const std::string	Bureaucrat::getName() const
{
	return(this->_name);
}

/***************************************************************************************/

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		if (form.isSigned() == true)
		{
			std::cout << YELLOW << form.getName() << " already signed " << RESET << std::endl;
			return;
		}
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET <<std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << YELLOW << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	if (this->getGrade() > form.getGradeToExecute())
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because their grade is too low." << std::endl;
		throw AForm::BureaucratGradeTooLowException();
	}
	if (!form.isSigned())
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because it wasn't signed." << std::endl;
		throw AForm::FormNotSignedException();
	}
	else
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
	}
	return;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Bureaucrat name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
	return (os);
}
