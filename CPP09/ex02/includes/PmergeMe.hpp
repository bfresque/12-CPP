/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 11:59:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <ctime>
# include <list>
# include <iterator>
# include <climits>

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

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#endif