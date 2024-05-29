/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/11 16:41:27 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
T const &min(T const &a, T const &b) { return ((a <= b) ? a : b); }

template <typename T>
T const &max(T const &a, T const &b) { return ((a >= b) ? a : b); }

template<typename T>
void swap(T &nb1, T &nb2) {
	T tmp;
	tmp = nb1;
	nb1 = nb2;
	nb2 = tmp;
}