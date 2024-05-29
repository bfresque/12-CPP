/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/12 11:36:32 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>
#define MAX_VAL 750

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	std::cout << WHITE << "Filling both numbers and mirror arrays with random values." << RESET << std::endl << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << WHITE << "Demonstrating deep copy:" << RESET << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "Checking that the copy does not modify the original." << std::endl << "Displaying some values..." << std::endl;
		std::cout << GREEN << "Original (numbers[0]): " << numbers[0] << std::endl;
		std::cout << "Copy     (tmp[0]) :    " << tmp[0] << RESET << std::endl << std::endl;
	}

	std::cout << WHITE << "Checking the integrity of numbers : " << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
				std::cerr << RED << "Integrity KO !!!" << RESET << std::endl;
			return 1;
		}
	}
	std::cout << GREEN << "Integrity OK !" << RESET << std::endl << std::endl;

	std::cout << WHITE  << "Testing access with a negative index : " << RESET << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception with negative index: " << e.what() << std::endl << std::endl;
	}

	std::cout << WHITE << "Testing access with an index equal to MAX_VAL : " << RESET << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception with index out-of-bounds: " << e.what() << std::endl << std::endl;
	}

	std::cout << WHITE << "Modifying the values in numbers" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		if (i == 0)
			std::cout << "New value of numbers numbers[0] : " << GREEN << numbers[0] << RESET << std::endl;
	}

	delete [] mirror;
	return 0;
}
