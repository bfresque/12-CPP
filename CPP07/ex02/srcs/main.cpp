/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/05 12:37:28 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main()
{
	try
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = i * 10;

		Array<int> arrCopy = arr;
		arrCopy[2] = 100;

		std::cout << "Original array: ";
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << " ";

		std::cout << "\nCopy array: ";
		for (unsigned int i = 0; i < arrCopy.size(); ++i)
			std::cout << arrCopy[i] << " ";

		std::cout << "\n";

		std::cout << "Accessing out of bounds: ";
		std::cout << arr[arr.size()] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: out of bounds access." << std::endl;
	}

	return (0);
}