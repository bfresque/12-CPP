/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/05 11:05:29 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>

T const min(T const &nb1, T const &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

template<typename T>

T const max(T const &nb1, T const &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

template<typename T>

void swap(T &nb1, T &nb2)
{
	T temp;
	temp = nb1;
	nb1 = nb2;
	nb2 = temp;
}
