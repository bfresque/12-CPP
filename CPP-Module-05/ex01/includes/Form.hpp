/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:13 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 14:07:40 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signedStatus;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		const std::string&	getName() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form &F);

#endif
