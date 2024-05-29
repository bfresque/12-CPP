/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:17:54 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 16:03:34 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called "<< std::endl;
	return;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Constructor, "<< this->_name << " is ready to fight !" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = copy;
	return;
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor, " << this->_name << " has left the fight !" << std::endl;
	return;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints <= 0)
		std::cout << RED << "FragTrap " << this->_name << " tried to do a high five, but has no energy left." << RESET << std::endl;
	else if(this->_hitPoints <= 0)
		std::cout << RED << "FragTrap " << this->_name << " tried to do a high five, but has no hit points left." << RESET << std::endl;
	else
		std::cout << CYAN << "FragTrap " << this->_name << " said: Guys it's time for a high five !!" << RESET << std::endl;
	return;
}
