/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:29 by bfresque          #+#    #+#             */
/*   Updated: 2024/01/31 12:18:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phone;
	std::string command;

	//ici appel de commande
	while(command != "EXIT")
	{
		std::cout << " Enter a command : ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phone.add();
		}
		else if (command == "SEARCH")
		{
			phone.search();
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		// if (std::cin.eof())
		// {
		// 	std::cin.clear();
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 	return;
		// }
	}
	return (0);
}
