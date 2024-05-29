/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:39 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 14:37:45 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *hordeZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		hordeZombie[i].setName(name);
	return (hordeZombie);
}
