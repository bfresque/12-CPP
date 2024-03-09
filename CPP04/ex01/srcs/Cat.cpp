/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:38:56 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:23:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	_myBrain = new Brain();
	return;
}

Cat::Cat(const Cat &copy) : Animal("Cat")
{
	std::cout << "Cat Copy constructor called" <<std::endl;
	_myBrain = new Brain(*copy._myBrain);
	//pas besoin de *this = copy; ????
	return;
}

Cat::~Cat()
{
	std::cout << "Cat Default destructor called" <<std::endl;
	delete _myBrain;
	return;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete _myBrain;
		_myBrain = new Brain(*other._myBrain);
	}
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooww!!!" << std::endl;
	return;
}

Brain	*Cat::getBrain(void) const
{
	return (_myBrain);
}