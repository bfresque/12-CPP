/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:52:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 14:17:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);
		void	annouce(void) const;
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
