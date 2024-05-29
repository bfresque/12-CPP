/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/11 17:00:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl << std::endl;
	
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl << std::endl;

	std::string stringArray[] = {"bleu", "magenta", "jaune", "vert", "violet"};
	iter(stringArray, 5, printElement<std::string>);
	std::cout << std::endl << std::endl;

	return (0);
}