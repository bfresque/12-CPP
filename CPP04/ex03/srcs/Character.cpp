/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:06 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:06:15 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "(null)";
	return;
}

Character::Character(std::string name)
{
	std::cout << "Character type constructor called" << std::endl;
	this->_name = name;
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
	std::cout << "Character destructor called" << std::endl;
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

void Character::equip(AMateria* newMateria)
{
	if (!newMateria)
	{
		std::cout << "Error. No materia provided" << std::endl;
		return;
	}
	if (this->_nbMateria >= 4)
	{
		std::cout << "Error. No more space in inventory" << std::endl;
		delete newMateria;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = newMateria;
			std::cout << getName() << " is equipped with a new materia : " << newMateria->getType();
			std::cout << " index : " << i << std::endl;
			this->_nbMateria++;
			return;
		}
	}
	std::cout << "Error. No more space in inventory" << std::endl;
	delete newMateria;
	return;
}

void Character::unequip(int index)
{
	if (index < 0 || index >= 4)
	{
		std::cout << "Invalid index: " << index << std::endl;
		return;
	}
	if (!this->_inventory[index])
	{
		std::cout << getName() << " has nothing to un-equip in the index : " << index << std::endl;
		return;
	}
	std::cout << getName() << " has un-equipped materia : " << this->_inventory[index]->getType();
	std::cout << " index : " << index << std::endl;
	delete this->_inventory[index];
	this->_inventory[index] = NULL;
	this->_nbMateria--;
	return;
}

void Character::use(int index, ICharacter& target)
{
	if (index >= 0 && index < _nbMateria && this->_inventory[index] != NULL)
		this->_inventory[index]->use(target);
	return;
}