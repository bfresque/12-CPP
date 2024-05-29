/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:38:56 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 14:34:01 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" <<std::endl;
	return;
}

Cat::Cat(const Cat &copy) : Animal("Cat")
{
	std::cout << "Cat Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

Cat::~Cat()
{
	std::cout << "Cat Default destructor called" <<std::endl;
	return;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator called" <<std::endl;
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meoooww!!!" << std::endl;
	return;
}
