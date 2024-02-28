/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:49 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/26 12:26:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define MAX_HEALTH 10
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif