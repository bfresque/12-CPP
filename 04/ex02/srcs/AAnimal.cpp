/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:30:33 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 14:36:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor called" <<std::endl;
	this->type = "AAnimal by default";
	return;
}

AAnimal::AAnimal(const std::string &type)
{
	std::cout << "AAnimal constructor called" <<std::endl;
	this->type = type;
	return;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Default destructor called" <<std::endl;
	return;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignement operator called" <<std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "... Pshhhhhh ..." << std::endl;
	return;
}

Brain	*AAnimal::getBrain(void) const
{
	std::cout << "OH okay .. Where am I ?" << std::endl;
	return (0);
}
