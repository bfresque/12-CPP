/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:33:33 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/02 15:07:02 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main (void)
{
	std::string str;
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	str = "HI THIS IS BRAIN";

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << std::endl;
	
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}
