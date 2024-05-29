/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:50:10 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/05 11:50:59 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon& newWeapon);
		~HumanA(void);
		void	attack(void) const;
};

#endif
