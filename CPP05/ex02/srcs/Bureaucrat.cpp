/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:19 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/19 11:47:57 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultB"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(int grade) : _name("DefaultB"), _grade(grade)
{
	std::cout << "Bureaucrat Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat Constructor called for : " << WHITE << getName() << RESET << " with the grade : " << WHITE << getGrade() << RESET << std::endl;
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

std::string	Bureaucrat::getName() const
{
	return(this->_name);
}

/***************************************************************************************/

void Bureaucrat::signAForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->_name << " signed " << AForm.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn’t sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << "Bureaucrat " << b.getName() << "\n Grade: " << b.getGrade() << std::endl;
	return (o);
}


