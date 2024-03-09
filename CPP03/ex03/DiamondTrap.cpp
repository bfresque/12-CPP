/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:44:18 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 14:23:38 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_name_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = "Default_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default Constructor called "<< std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Constructor, "<< this->_name << " is ready to fight !" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = copy;
	return;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &other)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = other._name + "_clap_trap";
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor, " << this->_name << " has left the fight !" << std::endl;
	return;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return;
}

void	DiamondTrap::whoAmI()
{
	if (this->_energyPoints <= 0)
		std::cout << RED << "DiamondTrap " << this->_name << " tries to express himself, but has no energy left." << RESET << std::endl;
	else if(this->_hitPoints <= 0)
		std::cout << RED << "DiamondTrap " << this->_name << " tries to express himself, but has no hit points left." << RESET << std::endl;
	else
	std::cout << CYAN << "DiamondTrap my name is : " << this->_name << " and my ClapTrap name is : " << ClapTrap::_name << RESET << std::endl;
	return;
}
