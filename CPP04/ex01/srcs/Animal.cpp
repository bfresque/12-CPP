/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:30:33 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:27:31 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" <<std::endl;
	return;
}

Animal::Animal(const std::string type)
{
	std::cout << "Animal constructor called" <<std::endl;
	this->type = type;
	return;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

Animal::~Animal()
{
	std::cout << "Animal Default destructor called" <<std::endl;
	return;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignement operator called" <<std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "... Pshhhhhh ..." << std::endl;
	return;
}

Brain	*Animal::getBrain(void) const
{
	std::cout << "OH okay .. where am I ?" << std::endl;
	return (0);
}
