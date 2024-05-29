/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:38:46 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 14:34:08 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" <<std::endl;
	return;
}

Dog::Dog(const Dog &copy) : Animal("Dog")
{
	std::cout << "Dog Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

Dog::~Dog()
{
	std::cout << "Dog Default destructor called" <<std::endl;
	return;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement operator called" <<std::endl;
	this->type = other.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
	return;
}
