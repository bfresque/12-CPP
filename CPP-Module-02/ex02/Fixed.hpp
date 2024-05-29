/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/06 14:15:13 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_n;
		static const int _value = 8;
	public:
		Fixed();
		Fixed(const int integerNum);
		Fixed(const float floatNum);
		Fixed(const Fixed &copy);
		~Fixed();
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		Fixed &operator=(const Fixed &rhs);

		int				toInt(void) const;
		float			toFloat(void) const;
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		static			Fixed& min(Fixed& nb1, Fixed& nb2);
		static const	Fixed& min(const Fixed& nb1, const Fixed& nb2);
		static			Fixed& max(Fixed& nb1, Fixed& nb2);
		static const	Fixed& max(const Fixed& nb1, const Fixed& nb2);
};


std::ostream& operator<<(std::ostream& os, const Fixed& fi);

#endif