/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 15:17:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Jim("Jim");
	FragTrap	Bob("Bob");
	ClapTrap	test("test");

	std::cout << std::endl;
	test.attack("his best friend");
	test.takeDamage(7);
	test.beRepaired(2);

	
	Jim.attack("his best friend");
	Jim.takeDamage(7);
	Jim.beRepaired(2);
	Jim.takeDamage(5);
	Jim.highFivesGuys();
	Jim.takeDamage(90);
	Jim.attack("his best friend");
	Jim.beRepaired(42);

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		Bob.attack("a stone");
	Bob.highFivesGuys();
	Bob.takeDamage(99);
	// for (int i = 0; i < 96; i++)
	// 	Bob.beRepaired(1);
	Bob.attack("a stone");
	Bob.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
