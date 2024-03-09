/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:05:41 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 15:13:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor called" <<std::endl;
	return;
}

WrongAnimal::WrongAnimal(const std::string type)
{
	std::cout << "WrongAnimal constructor called" <<std::endl;
	this->type = type;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default destructor called" <<std::endl;
	return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignement operator called" <<std::endl;
	this->type = other.type;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "... Rwaaah ..." << std::endl;
	return;
}