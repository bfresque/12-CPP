/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:42 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/06 14:16:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_n = 0;
	return;
}

Fixed::~Fixed()
{
	return;
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
	return;
}

Fixed::Fixed(const int integerNum)
{
	this->setRawBits(integerNum << this->_value);
	return;
}

Fixed::Fixed(const float floatNum)
{
	int twoPower = 1 << this->_value;
	int rawValue = (int)roundf(floatNum * twoPower);
	this->setRawBits(rawValue);
	return;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	this->_n = rhs.getRawBits();
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> this->_value);
}

float	Fixed::toFloat(void) const
{
	int twoPower = 1 << this->_value;
	return (static_cast<float>(this->_n) / twoPower);
}

int	Fixed::getRawBits(void) const
{
	return(this->_n);
}

void	Fixed::setRawBits(const int raw)
{
	this->_n = raw;
	return;
}

Fixed&	Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.getRawBits() < nb2.getRawBits())
		return (nb1);
	else
		return (nb2);
}

Fixed&	Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	else
		return (nb2);
}

const Fixed&	Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	else
		return (nb2);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->_n > rhs._n);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->_n < rhs._n);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_n >= rhs._n);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_n <= rhs._n);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_n == rhs._n);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_n != rhs._n);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->_n + rhs._n);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->_n - rhs._n);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->_n += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_n -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	return (o << f.toFloat());
}
