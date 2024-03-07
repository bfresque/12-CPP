/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/06 13:40:52 by bfresque         ###   ########.fr       */
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
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


std::ostream& operator<<(std::ostream& os, const Fixed& fi);

#endif