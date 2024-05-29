/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:33 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 13:13:58 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main (void)
{
	Zombie *zombie1;

	zombie1 = newZombie("Bob");
	zombie1->annouce();
	delete zombie1;
	
	randomChump("Jim");
	return (0);
}