/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:37 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 13:13:02 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// new_zombie (prend un estring en parametre )
// appelle zombie en envoyant la string en parametre qui sera dans la fonction zombie
// renvoie la classse creerr dynamiquement 

Zombie	*newZombie(std::string name)
{
	Zombie *createZombie = new Zombie(name);
	return (createZombie);
}