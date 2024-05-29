/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:26:29 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/22 11:33:27 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void	ShrubberyCreationForm::specificExecute(void) const
{
	std::ofstream outfile;

	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.is_open())
	{
			outfile << "          ^  ^  ^" << std::endl;
			outfile << "         /|\\/|\\/|\\" << std::endl;
			outfile << "        /_|\\/|\\/|\\" << std::endl;
			outfile << "         /|\\/|\\/|\\" << std::endl;
			outfile << "        /_|\\/|\\/|\\" << std::endl;
			outfile << "         /|\\/|\\/|\\" << std::endl;
			outfile << "        /_|\\/|\\/|\\" << std::endl;
			outfile << "         /|\\/|\\/|\\" << std::endl;
			outfile << "        /_|\\/|\\/|\\" << std::endl;
			outfile << "          |  |  |" << std::endl;
			outfile << "          |  |  |" << std::endl;
			outfile << "          |  |  |" << std::endl;
			outfile << "         _|__|__|_" << std::endl;
			outfile.close();
	}
	return;
}
