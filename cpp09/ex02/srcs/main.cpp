/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/24 17:47:55 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "Usage: ./PmergeMe [numbers to organize]\n";
		return (1);
	}

	std::clock_t clock_begin_vector = std::clock();
	std::vector<int> numbers_vector;
	for (size_t i = 1; i < (size_t)ac; i++) {
		std::string arg = av[i];
		if (!is_positive_integer(arg)) {
			std::cerr << "Must be a positive integer(without sign): " << arg << std::endl;
			return (1);
		}
		char* endptr;
		long num = strtol(arg.c_str(), &endptr, 10);
		numbers_vector.push_back(static_cast<int>(num));
	}
	std::vector<int> merged_vector = ford_johnson_sort_vector(numbers_vector);
	std::clock_t clock_end_vector = std::clock();

	std::clock_t clock_begin_list = std::clock();
	std::list<int> numbers_list;
	for (size_t i = 1; i < (size_t)ac; i++) {
		std::string arg = av[i];
		if (!is_positive_integer(arg)) {
			std::cerr << "Must be a positive integer: " << arg << std::endl;
			return (1);
		}
		char* endptr;
		long num = strtol(arg.c_str(), &endptr, 10);
		if (*endptr != '\0' || num <= 0 || num > INT_MAX) {
			std::cerr << "Invalid number: " << arg << std::endl;
			return (1);
		}
		if (has_duplicates(numbers_list, static_cast<int>(num))) {
			std::cerr << "Duplicate number: " << num << std::endl;
			return (1);
		}
		numbers_list.push_back(static_cast<int>(num));
	}
	std::list<int> merged_list = ford_johnson_sort_list(numbers_list);
	std::clock_t clock_end_list = std::clock();

	std::cout << "Before:";
	for (size_t i = 1; i < (size_t)ac; i++)
		std::cout << " " << av[i];
	std::cout << std::endl;

	print_container<std::list<int> >(merged_list, "After");

	double duration_vector = (clock_end_vector - clock_begin_vector) * (1000000.0 / CLOCKS_PER_SEC);
	double duration_list = (clock_end_list - clock_begin_list) * (1000000.0 / CLOCKS_PER_SEC);

	std::cout << std::fixed << std::setprecision(0);
	std::cout << "Time to process a range of " << numbers_list.size() << " elements with std::vector : " << duration_vector << "µs\n";
	std::cout << "Time to process a range of " << numbers_list.size() << " elements with std::list :   " << duration_list << "µs\n";

	result(duration_vector, duration_list);
	return (0);
}
