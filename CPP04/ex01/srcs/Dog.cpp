/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:38:46 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:24:10 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" <<std::endl;
	_myBrain = new Brain();
	return;
}

Dog::Dog(const Dog &copy) : Animal("Dog")
{
	std::cout << "Dog Copy constructor called" <<std::endl;
	_myBrain = new Brain(*copy._myBrain);
	//pas besoin de *this = copy; ????
	return;
}

Dog::~Dog()
{
	std::cout << "Dog Default destructor called" <<std::endl;
	delete _myBrain;
	return;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete _myBrain; // Delete existing brain to avoid memory leak
		_myBrain = new Brain(*other._myBrain);
	}
	this->type = other.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
	return;
}

Brain	*Dog::getBrain(void) const
{
	return (_myBrain);
}
