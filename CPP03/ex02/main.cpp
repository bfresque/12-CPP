/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/01 10:42:29 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Jim("Jim");
	FragTrap	Bob("Bob");

	std::cout << std::endl;
	Jim.attack("his best friend");
	Jim.takeDamage(7);
	Jim.beRepaired(2);
	Jim.takeDamage(5);
	Jim.takeDamage(90);
	Jim.attack("his best friend");
	Jim.beRepaired(42);

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		Bob.attack("a stone");
	Bob.highFivesGuys();
	Bob.takeDamage(99);
	Bob.beRepaired(1);
	Bob.takeDamage(2);
	Bob.attack("a stone");
	std::cout << std::endl;
	return (0);
}
// faire des boucles pour tester l'energy_points