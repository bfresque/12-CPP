/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:13 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/18 11:15:22 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat; // Forward declaration

class AForm
{
	private:
		const std::string	_name;
		bool				_signedStatus;
		const int			_gradeToSign;
		const int			_gradeToExecute; 
	
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		const std::string&	getName() const;

		void beSigned(const Bureaucrat& bureaucrat);
		void executeForm(AForm const& form);

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

std::ostream	&operator<<(std::ostream &o, AForm *F);

#endif
