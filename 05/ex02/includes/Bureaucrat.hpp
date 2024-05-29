/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:05:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 09:55:31 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "./AForm.hpp"
# include <iostream>
# include <exception>
# include <string>

# define BLACK	"\033[1m\033[30m"
# define RED		"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define YELLOW	"\033[1m\033[33m"
# define BLUE	"\033[1m\033[34m"
# define MAGENTA	"\033[1m\033[35m"
# define CYAN	"\033[1m\033[36m"
# define WHITE	"\033[1m\033[37m"
# define RESET	"\033[0m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &Bureaucrat);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);

		void		decrementGrade();
		void		incrementGrade();

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

		void		setGrade(int grade);
		int			getGrade() const;
		const std::string	getName() const;

		void	signAForm(AForm& AForm);
		void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
