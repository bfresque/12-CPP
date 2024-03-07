/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:46 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/07 10:06:29 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap Default Constructor called "<< std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap Constructor, "<< this->_name << " is ready to fight !" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor, " << this->_name << " has left the fight !" << std::endl;
	return;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
		std::cout << RED << "ClapTrap " << this->_name << " tries to attack " << target << ", but has no energy left." << RESET << std::endl;
	else if(this->_hitPoints <= 0)
		std::cout << RED << "ClapTrap " << this->_name << " tries to attack " << target << ", but has no hit points left." << RESET << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
		this->_energyPoints--;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage, ";
		if (this->_hitPoints <= 0)
		{
			std::cout << "no more hit points left, he is dead" << std::endl;
			this->_hitPoints = 0;
		}
		else
			std::cout << this->_hitPoints << " hit points left" << std::endl;
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->_name << " is already dead" << RESET << std::endl;
	return;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " tried to resurrect himself with " << amount << " hit points, but unfortunately he's far too dead." << RESET << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " tried to repair itself with " << amount << " hit points, but has no energy left." << RESET << std::endl;
		return ;
	}
	else
	{
		if (amount <= 0)
		{
			std::cout << "ClapTrap " << "Amount must be positive interger" << std::endl;
			return;
		}
		this->_energyPoints--;
		if ((this->_hitPoints + amount) > MAX_HEALTH)
		{
			std::cout << "ClapTrap " << this->_name << " repaired itself with " << amount << " hit points. He have " << (MAX_HEALTH - this->_hitPoints) << " hit points. And " << this->_energyPoints << " energy left." << std::endl;
			this->_hitPoints = MAX_HEALTH;
			return;
		}
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself with " << amount << " hit points. He have " << this->_hitPoints << " hit points. And " << this->_energyPoints << " energy left." << std::endl;
	}
	return;
}

