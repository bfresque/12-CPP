/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 12:22:51 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Jim("Jim");
	ScavTrap	Bob("Bob");

	std::cout << std::endl;
	Jim.attack("his enemy");
	Jim.takeDamage(7);
	Jim.beRepaired(2);
	Jim.takeDamage(5);
	Jim.takeDamage(90);
	Jim.attack("his enemy");
	Jim.beRepaired(42);

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		Bob.attack("a branch");
	Bob.guardGate();
	Bob.takeDamage(99);
	Bob.beRepaired(1);
	Bob.takeDamage(2);
	Bob.attack("a branch");
	std::cout << std::endl;
	return (0);
}
