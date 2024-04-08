/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/05 11:15:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


template<typename T, typename Function>

void	iter(T* array, int len, Function f)
{
	int i = 0;

	while (i < len)
	{
		f(array[i]);
		i++;
	}
}
