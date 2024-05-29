/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 15:20:39 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	Bob("Bob");
	ScavTrap	Jim("Jim");
	FragTrap	Tom("Tom");
	DiamondTrap	Sun("Sun");
	DiamondTrap	Default;

	std::cout << "\n    ~~~ Default's fight ~~~" << std::endl;
	Default.attack("a tree");
	Default.takeDamage(7);

	std::cout << "\n    ~~~ Bob's fight ~~~" << std::endl;
	Bob.attack("a Zombie");
	Bob.takeDamage(7);
	Bob.beRepaired(2);
	Bob.takeDamage(5);
	Bob.takeDamage(90);
	Bob.attack("a Zombie");
	Bob.beRepaired(42);

	std::cout << "\n    ~~~ Jim's fight ~~~" << std::endl;
	for (int i = 0; i < 5; i++)
		Jim.attack("a stone");
	Jim.guardGate();
	Jim.takeDamage(99);
	Jim.beRepaired(1);
	Jim.takeDamage(2);
	Jim.attack("a stone");
	Jim.guardGate();

	std::cout << "\n    ~~~ Tom's fight ~~~" << std::endl;
	Tom.highFivesGuys();
	for (int i = 0; i < 5; i++)
		Tom.attack("a door");
	Tom.highFivesGuys();
	Tom.takeDamage(42);
	Tom.beRepaired(24);
	Tom.takeDamage(42);
	Tom.attack("a door");
	Tom.highFivesGuys();

	std::cout << "\n    ~~~ Sun's fight ~~~" << std::endl;
	Sun.whoAmI();
	Sun.takeDamage(42);
	Sun.beRepaired(24);
	Sun.takeDamage(24);
	Sun.takeDamage(420);
	Sun.beRepaired(42);
	Sun.whoAmI();

	std::cout << std::endl;
	return (0);
}