/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 12:46:10 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Default;
	ClapTrap OtherMan(Default);
	ClapTrap Bob("Bob");

	std::cout << std::endl;
	Default.attack("some Zombie");
	Default.takeDamage(5);
	Default.beRepaired(20);
	Default.takeDamage(10);
	Default.takeDamage(10);
	Default.beRepaired(5);
	Default.attack("Bob");

	std::cout << std::endl;
	Bob.beRepaired(3);
	for (int i = 0; i < 12; i++)
		Bob.attack("a random guy");
	Bob.beRepaired(3);

	std::cout << std::endl;
	return (0);
}
