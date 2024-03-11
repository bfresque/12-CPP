/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:14:10 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:41:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return;
}

Ice::Ice(const Ice &copy) : AMateria(copy._type)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
	return;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return;
}

Ice& Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const & Ice::getType() const
{
	return(this->_type);
}

Ice* Ice::clone() const
{
	Ice *cloneIce = new Ice(*this);
	return (cloneIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " <<  target.getName() << " *" << std::endl;
	return;
}