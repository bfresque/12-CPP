/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 09:43:20 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "NULL";
	return;
}

AMateria::AMateria(const std::string &type)
{
	std::cout << "AMateria type constructor called" << std::endl;
	this->_type = type;
	return;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
	return;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
	return;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use on " << target.getName() << std::endl;
	return;
}