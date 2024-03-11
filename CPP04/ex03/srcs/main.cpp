/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:06:30 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/11 17:41:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/AMateria.hpp"
# include "../includes/IMateriaSource.hpp"
# include "../includes/MateriaSource.hpp"
# include "../includes/ICharacter.hpp"
# include "../includes/Character.hpp"
# include "../includes/Cure.hpp"
# include "../includes/Ice.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}