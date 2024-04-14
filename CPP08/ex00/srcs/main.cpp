/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/14 18:32:37 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main() {
	// std::vector<int> vec = {1, 2, 3, 4, 5};
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	int num1 = 3;
	int num2 = 42;
	try {
		int *found = easyfind(vec, num1);
		std::cout << "Number found at address: " << found << std::endl;
		found = easyfind(vec, num2);
		std::cout << "Number found at address: " << found << std::endl;
	}
	catch (const NotFound& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}