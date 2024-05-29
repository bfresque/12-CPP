/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:16:11 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 09:45:07 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/MateriaSource.hpp"

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
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
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

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_nbMateria == 4)
	{
		std::cout << YELLOW << "MateriaSource can't learn more than 4 materias" << RESET << std::endl;
		delete m;
	}
	else if (this->_nbMateria < 4 && m != NULL)
	{
		for (int i = 0; i < this->_nbMateria; i++) {
			if (this->_inventory[i] == m) {
				std::cout << YELLOW << "MateriaSource " <<  m->getType() << "is already learned" << RESET << std::endl;
				return;
			}
		}
		this->_inventory[this->_nbMateria++] = m;
		std::cout << BOLD_WHITE << "MateriaSource learned materia \"" << m->getType() << "\"" << RESET << std::endl;
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_nbMateria; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << BOLD_WHITE << "MateriaSource created materia \"" << type << "\"" << RESET << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	return (NULL);
}
