/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:13 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/18 11:15:22 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat; // Forward declaration

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

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream	&operator<<(std::ostream &o, Form *F);

#endif
