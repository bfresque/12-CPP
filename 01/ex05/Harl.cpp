/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:57:00 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/07 10:46:17 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do !" << std::endl;
	return;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger ! ";
	std::cout << "If you did, I wouldn’t be asking for more !" << std::endl;
	return;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working ";
	std::cout << "here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unaCXXeptable ! I want to speak to the manager now.";
	std::cout << std::endl;
	return;
}

void Harl::complain(std::string level)
{
	// J'associe de chaque niveau à sa fonction
	t_level levelFunctions[4] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}
	};
	// Je parcours le tableau pour trouver la fonction correspondante au niveau donné
	for (int i = 0; i < 4; i++)
	{
		if (level == levelFunctions[i].level)
		{
			(this->*(levelFunctions[i].function))();
			return;
		}
	}
	std::cout << "Error: Unknown level '" << level << "'" << std::endl;
	return;
}
