/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/24 17:44:46 by bfresque         ###   ########.fr       */
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

# define INT_MAX 2147483647

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
bool is_positive_integer(const std::string& str);
bool has_duplicates(const std::list<int>& numbers, int num);
void result(double vectorTime, double listTime);

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif