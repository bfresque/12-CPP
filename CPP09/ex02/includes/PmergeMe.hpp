/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 18:05:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <list>
# include <iomanip>

# define RED	"\033[1;31m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

template <typename T>
void print_container(T container, const std::string& message)
{
	std::cout << message << ":";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}
std::vector<int> ford_johnson_sort_vector(std::vector<int> v);
std::list<int> ford_johnson_sort_list(std::list<int> l);
bool is_positive_integer(const char *str);
bool has_duplicates(const std::vector<int>& numbers, int num);
void result(clock_t vectorTime, clock_t listTime);

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif