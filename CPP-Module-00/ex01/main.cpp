/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:29 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/01 10:26:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		PhoneBook	phone;
		std::string command;

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
		}
		return (0);
	}
	std::cout << "Only one argument" << std::endl;
	(void)av;
	return (0);
}
