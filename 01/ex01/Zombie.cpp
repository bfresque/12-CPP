/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:42 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 14:24:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " is destroyed\n";
	return;
}
void	Zombie::setName(std::string name)
{
	this->_name = name;
	return;
}

void	Zombie::annouce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}