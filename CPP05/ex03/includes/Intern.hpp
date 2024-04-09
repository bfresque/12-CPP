/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:42:38 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/09 16:19:49 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		// Intern& operator=(const Intern &other);
		AForm	*makeForm(const std::string newForm, const std::string targetFrom);

};

#endif
