/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:07:14 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 15:09:20 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" <<std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Default destructor called" <<std::endl;
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignement operator called" <<std::endl;
	this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meoooww!!!" << std::endl;
	return;
}
