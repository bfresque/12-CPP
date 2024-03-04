/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:44:18 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/01 12:43:04 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_name_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default Constructor called "<< std::endl;
	this->_name = "Default_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Constructor, "<< this->_name << " is ready to fight !" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
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

// void	attack(const std::string &target)
// {
// 	ScavTrap::attack(target);
// 	return;
// }

void	whoAmI()
{
	return;
}