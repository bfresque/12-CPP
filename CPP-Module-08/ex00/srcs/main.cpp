/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/16 15:12:45 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main() {
	int arr[] = { 103, 14, 12, 123, 73, 4, 3, 55};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	int num1 = 3;
	int num2 = 42;
	try {
		std::vector<int>::iterator found = easyfind(vec, num1);
		std::cout << GREEN << "\nNumber " << num1 << " found at position: " << std::distance(vec.begin(), found) << RESET << std::endl << std::endl;
		found = easyfind(vec, num2);
		std::cout << GREEN << "\nNumber " << num2 << " found at position: " << std::distance(vec.begin(), found) << RESET << std::endl << std::endl;
	}
	catch (const NotFound& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}