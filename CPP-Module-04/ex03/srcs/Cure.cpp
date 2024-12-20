/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:14:02 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 09:46:08 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure::Cure(const Cure &copy) : AMateria(copy._type)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
	return;
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RESET << std::endl;
	return;
}

Cure& Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const & Cure::getType() const
{
	return(this->_type);
}

Cure* Cure::clone() const
{
	Cure *cloneCure = new Cure(*this);
	return (cloneCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "* heals " <<  target.getName() << "\'s wounds *" << RESET << std::endl;
	return;
}
