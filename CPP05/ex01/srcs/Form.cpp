/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:19:02 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/21 11:35:07 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form()
	: _name("DefaultF"), _signedStatus(false), _gradeToSign(150), _gradeToExecute(150)
{
	return;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	return;
}

Form::Form(const Form& other)
	: _name(other._name), _signedStatus(other._signedStatus), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	return;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signedStatus = other._signedStatus;
	return (*this);
}

Form::~Form()
{
	return;
}

const	std::string& Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	return (this->_signedStatus);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signedStatus = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName()
	  << " (Signed: " << (f.isSigned() ? "Yes" : "No")
	  << ", Grade to Sign: " << f.getGradeToSign()
	  << ", Grade to Execute: " << f.getGradeToExecute() << ")";
	return (os);
}
