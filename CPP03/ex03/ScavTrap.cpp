/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:46 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/29 11:11:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called "<< std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Constructor, "<< this->_name << " is ready to fight !" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = copy;
	return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor, " << this->_name << " has left the fight !" << std::endl;
	return;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
		std::cout << RED << "ScavTrap " << this->_name << " tries to attack " << target << ", but has no energy left." << RESET << std::endl;
	else if(this->_hitPoints <= 0)
		std::cout << RED << "ScavTrap " << this->_name << " tries to attack " << target << ", but has no hit points left." << RESET << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	if (this->_energyPoints <= 0)
		std::cout << RED << "ScavTrap " << this->_name << " tries to guarding the gate, but has no energy left." << RESET << std::endl;
	else if(this->_hitPoints <= 0)
		std::cout << RED << "ScavTrap " << this->_name << " tries to guarding the gate, but has no hit points left." << RESET << std::endl;
	else
	std::cout << CYAN << "ScavTrap " << this->_name << " is now guarding the gate." << RESET << std::endl;
	return;
}
