/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:48:54 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 10:30:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	std::cout << "---------------------------------" << std::endl;
	const Animal* Default = new Animal();
	std::cout << "---------------------------------" << std::endl;
	const Animal* Catty = new Cat();
	std::cout << "---------------------------------" << std::endl;
	const Animal* Doggy = new Dog();
	std::cout << "---------------------------------" << std::endl;
	
	std::cout << std::endl;
	std::cout << Catty->getType() << " " << std::endl;
	std::cout << Doggy->getType() << " " << std::endl;
	std::cout << Default->getType() << " " << std::endl;
	std::cout << std::endl;
	Catty->makeSound(); // will output the cat sound!
	Doggy->makeSound();
	Default->makeSound();

	std::cout << "\n--------------------------------------" << std::endl;
	const WrongAnimal* WrongA = new WrongAnimal();
	std::cout << "--------------------------------------" << std::endl;
	const WrongAnimal* WrongC = new WrongCat();
	std::cout << "--------------------------------------" << std::endl;
	const WrongCat GoodCat;
	std::cout << "--------------------------------------\n" << std::endl;
	
	std::cout << WrongA->getType() << " " << std::endl;
	WrongA->makeSound();
	std::cout << "--------------------------------------" << std::endl;

	std::cout << WrongC->getType() << " " << std::endl;
	WrongC->makeSound(); // will output a wrong sound!
	std::cout << "--------------------------------------" << std::endl;
	
	std::cout << GoodCat.getType() << " " << std::endl;
	GoodCat.makeSound();
	std::cout << "--------------------------------------\n" << std::endl;

	delete Default;
	std::cout << "-------------------------------------" << std::endl;
	delete Catty;
	std::cout << "-------------------------------------" << std::endl;
	delete Doggy;
	std::cout << "-------------------------------------" << std::endl;
	delete WrongA;
	std::cout << "-------------------------------------" << std::endl;
	delete WrongC;
	std::cout << "-------------------------------------" << std::endl;
	return (0);
}
