/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:06 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 10:00:49 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "(null)";
	this->_nbMateria = 0;
	return;
}

Character::Character(std::string name)
{
	std::cout << "Character type constructor called" << std::endl;
	this->_name = name;
	this->_nbMateria = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return;
}

Character::~Character()
{
	std::cout << RED << "Character destructor called" << RESET << std::endl;
	for (int i = 0; i < this->_nbMateria; i++)
	{
		if (_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "~Character~ copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < this->_nbMateria; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		_nbMateria = other._nbMateria;
		for (int i = 0; i < this->_nbMateria; i++)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << YELLOW << "Error. No materia provided" << RESET << std::endl;
		return;
	}
	if (this->_nbMateria >= 4)
	{
		std::cout << YELLOW << "Error. No more space in inventory" << RESET << std::endl;
		delete m;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << BLUE << getName() << " is now equipped with a new materia : \"" << m->getType();
			std::cout << "\", in the index : " << i << RESET <<std::endl;
			this->_nbMateria++;
			return;
		}
	}
	std::cout << YELLOW << "Error. No more space in inventory" << RESET << std::endl;
	delete m;
	return;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << YELLOW << "Invalid index: " << idx << RESET << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << YELLOW << getName() << " has nothing to un-equip in the index : " << idx << RESET << std::endl;
		return;
	}
	std::cout << BLUE << getName() << " has un-equipped materia : " << this->_inventory[idx]->getType();
	std::cout << " index : " << idx << RESET << std::endl;
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	this->_nbMateria--;
	return;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _nbMateria && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	return;
}