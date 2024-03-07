/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:42 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/06 13:49:51 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() // constructeur par defaut
{
	this->_n = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed() // destructeur par defaut
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Fixed::Fixed(const int integerNum) // constructeur de int
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(integerNum << this->_value);
	return;
}

Fixed::Fixed(const float floatNum) // constructeur de float
{
	std::cout << "Float constructor called" << std::endl;
	int twoPower = 1 << this->_value;
	int rawValue = (int)roundf(floatNum * twoPower);
	this->setRawBits(rawValue);
	return;
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> this->_value);
}

float	Fixed::toFloat(void) const
{
	int twoPower = 1 << this->_value;
	return ((float)this->_n / twoPower);
}

void	Fixed::setRawBits(const int raw)
{
	this->_n = raw;
	return;
}

int	Fixed::getRawBits(void) const
{
	return(this->_n);
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	return (o << f.toFloat());
}
