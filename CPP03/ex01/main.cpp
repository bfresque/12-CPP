/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/26 11:36:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	int i = 0;
	ClapTrap Default;
	ClapTrap OtherMan(Default);
	ClapTrap Bob("Bob");

	std::cout << std::endl;
	Default.attack("some other robot");
	Default.takeDamage(10);
	Default.takeDamage(10);
	Default.beRepaired(5);
	Default.attack("some other other robot");
	std::cout << std::endl;
	Bob.beRepaired(3);
	while (i < 12)
	{
		Bob.attack(" Cody-clone");
		i++;
	}
	Bob.beRepaired(3);
	std::cout << std::endl;
	return (0);
}
// besoin de la fonction de surche d'operateur ou pas ???
