/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:46 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/29 11:10:49 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};

#endif