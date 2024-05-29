/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/11 16:57:41 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T, typename Function>
void	iter(T* array, int len, Function f) {
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void	printElement(T &element) { std::cout << element << std::endl; }