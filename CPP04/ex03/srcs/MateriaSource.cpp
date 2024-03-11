/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:11 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:05:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->_nbMateria = 0;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i]->clone();
	return;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->_nbMateria; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	return;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < this->_nbMateria; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		this->_nbMateria = other._nbMateria;
		for (int i = 0; i < _nbMateria; i++)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* newMateria)
{
	if (this->_nbMateria == 4)
	{
		std::cout << "MateriaSource can't learn more than 4 materias" << std::endl;
		delete newMateria;
	}
	else if (this->_nbMateria < 4 && newMateria != NULL)
	{
		for (int i = 0; i < this->_nbMateria; i++) {
			if (this->_inventory[i] == newMateria) {
				std::cout << "MateriaSource " <<  newMateria->getType() << "is already learned" << std::endl;
				return;
			}
		}
		this->_inventory[this->_nbMateria++] = newMateria;
		std::cout << "MateriaSource learned materia \"" << newMateria->getType() << "\"" << std::endl;
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_nbMateria; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << "MateriaSource created materia \"" << type << "\"" << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	return (NULL);
}
