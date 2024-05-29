/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:06:30 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 10:05:32 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/AMateria.hpp"
# include "../includes/IMateriaSource.hpp"
# include "../includes/MateriaSource.hpp"
# include "../includes/ICharacter.hpp"
# include "../includes/Character.hpp"
# include "../includes/Cure.hpp"
# include "../includes/Ice.hpp"

void	myMainExo()
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

	ICharacter* Gaga = new Character("Gaga");
	std::cout << std::endl;

	me->use(0, *Gaga);
	me->use(1, *Gaga);
	std::cout << std::endl;

	delete Gaga;
	delete me;
	delete src;
}

void	myMainBatt(void)
{

	ICharacter*	Batt = new Character("Batt");
	ICharacter*	Target = new Character("Target");
	IMateriaSource* srcBatt = new MateriaSource();

	std::cout << BLUE << "\n-----------------------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "|		Character " << Batt->getName() << " has been created			|" << RESET << std::endl;
	std::cout << BLUE << "-----------------------------------------------------------------\n" << RESET << std::endl;

	std::cout << CYAN << "\n-->  Batt tries to learn 5 materias" << RESET <<std::endl;
	srcBatt->learnMateria(new Cure());
	srcBatt->learnMateria(new Ice());
	srcBatt->learnMateria(new Cure());
	srcBatt->learnMateria(new Ice());
	srcBatt->learnMateria(new Cure());

	std::cout << CYAN << "\n-->  Batt removes 3 materias not yet equippe" << RESET << std::endl;
	Batt->unequip(0);
	Batt->unequip(3);
	Batt->unequip(12);

	std::cout << CYAN << "\n-->  Batt wants a matereria that doesn't exist" << RESET << std::endl;
	Batt->equip(srcBatt->createMateria("fire"));

	std::cout << CYAN << "\n-->  Batt tries to equip itself with 5 materias" << RESET << std::endl;
	Batt->equip(srcBatt->createMateria("ice"));
	Batt->equip(srcBatt->createMateria("cure"));
	Batt->equip(srcBatt->createMateria("ice"));
	Batt->equip(srcBatt->createMateria("cure"));
	Batt->equip(srcBatt->createMateria("ice")); // pas de place pour ce materia

	std::cout << CYAN << "\n-->  Batt uses his materias" << RESET << std::endl;
	Batt->use(0, *Target);
	Batt->use(1, *Target);
	Batt->use(2, *Target);
	Batt->use(3, *Target);
	Batt->use(4, *Target); // ne s'affiche pas car existe pas

	std::cout << CYAN << "\n-->  Batt removes 2 materias + 1 invalid" << RESET << std::endl;
	Batt->unequip(0);
	Batt->unequip(3);
	Batt->unequip(42);

	std::cout << CYAN << "\n-->  Batt equips with 1 new materia" << RESET << std::endl;
	Batt->equip(srcBatt->createMateria("cure"));
	Batt->equip(srcBatt->createMateria("ice"));
	Batt->equip(srcBatt->createMateria("cure")); // ne pourra pas s'equiper car plus de place

	std::cout << CYAN << "\n-->  ... Delete ..." << RESET << std::endl;
	delete srcBatt;
	delete Batt;
	delete Target;
	std::cout << std::endl;
}

int main()
{
	// myMainExo();
	myMainBatt();
}
