/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:48:54 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 12:38:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	Animal* animaux[6];

	for (int i = 0; i < 6; ++i)
	{
		std::cout << LINE << std::endl;
		if (i % 2 == 0)
		{
			animaux[i] = new Dog();
			animaux[i]->getBrain()->addIdeas("I love bones !");
		}
		else
		{
			animaux[i] = new Cat();
			animaux[i]->getBrain()->addIdeas("I love mouses !");
		}
	}
	std::cout << LINE << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		std::cout << "Hello here a " << animaux[i]->getType() << std::endl;
		animaux[i]->getBrain()->readBrain();
		animaux[i]->makeSound();
		std::cout << LINE << std::endl;
	}
	/*test deep copy*/
	Dog Doggy;
	Doggy->addIdeas("I love mouses !"); ///aalalalal
	
	{
		Dog DoggyCopy = Doggy;
	}

	for (int i = 0; i < 6; ++i)
	{
		delete animaux[i];
		std::cout << LINE << std::endl;
	}
	return (0);
}
