/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:19:02 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/18 11:14:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm()
	: _name("DefaultAF"), _signedStatus(false), _gradeToSign(150), _gradeToExecute(150)
{
	return;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	return;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signedStatus(other._signedStatus), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	return;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signedStatus = other._signedStatus;
	return (*this);
}

AForm::~AForm()
{
	return;
}

const	std::string& AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	return (this->_signedStatus);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signedStatus = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::BureaucratGradeTooLowException();
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	this->specificExecute();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form exception: form is not signed.");
}

const char *AForm::BureaucratGradeTooLowException::what() const throw()
{
	return ("Form exception: Bureaucrat grade is too low.");
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
	os << "Form " << f.getName()
	  << " (Signed: " << (f.isSigned() ? "Yes" : "No")
	  << ", Grade to Sign: " << f.getGradeToSign()
	  << ", Grade to Execute: " << f.getGradeToExecute() << ")";
	return (os);
}