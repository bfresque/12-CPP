/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:33 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 14:33:23 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main (void)
{
	Zombie *HordeZ;
	std::string name;
	int size;

	name = "Test";
	size = 10;
	HordeZ = zombieHorde(size, name);
	for (int i = 0; i < size; i++)
		HordeZ[i].annouce();
	delete [] HordeZ;
	return (0);
}