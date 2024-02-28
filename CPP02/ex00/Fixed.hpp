/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/20 10:56:54 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_n;
		static const int _value = 8;
	public:
		Fixed();
		Fixed(Fixed &copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif