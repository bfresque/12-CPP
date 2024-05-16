/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/16 15:43:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage: ./PmergeMe [numbers to organize]\n";
		return 1;
	}

	std::vector<int> numbers_vector;
	for (size_t i = 1; i < (size_t)ac; i++)
	{
		int num = atoi(av[i]);
		if (num < 0)
		{
			std::cerr << "Negative number not allowed: " << num << std::endl;
			return 1;
		}
		numbers_vector.push_back(num);
	}

	std::clock_t clock_begin_vector = std::clock();
	std::vector<int> merged_vector = ford_johnson_sort_vector(numbers_vector);
	std::clock_t clock_end_vector = std::clock();

	std::list<int> numbers_list;
	for (size_t i = 1; i < (size_t)ac; i++)
	{
		int num = atoi(av[i]);
		if (num < 0)
		{
			std::cerr << "Negative number: " << num << std::endl;
			return 1;
		}
		numbers_list.push_back(num);
	}
	std::clock_t clock_begin_list = std::clock();
	std::list<int> merged_list = ford_johnson_sort_list(numbers_list);
	std::clock_t clock_end_list = std::clock();

	std::cout << "Before:";
	for (size_t i = 1; i < (size_t)ac; i++)
		std::cout << " " << av[i];
	std::cout << std::endl;

	print_container<std::vector<int> >(merged_vector, "After");

	double duration_vector = (clock_end_vector - clock_begin_vector) / (double)CLOCKS_PER_SEC * 1000;
	double duration_list = (clock_end_list - clock_begin_list) / (double)CLOCKS_PER_SEC * 1000;

	std::cout << std::fixed << "Time to process a range of " << numbers_list.size() << " elements with std::vector : " << duration_vector << "ms\n";
	std::cout << "Time to process a range of " << numbers_list.size() << " elements with std::list : " << duration_list << "ms\n";

	return 0;
}
