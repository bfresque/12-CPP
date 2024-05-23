/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 18:05:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::PmergeMe::~PmergeMe() { }

bool is_positive_integer(const char *str) {
	for (int i = 0; str[i] != '\0'; i++)
		if (!std::isdigit(str[i])) {
			return (false);
	}
	return (true);
}

void result(clock_t vectorTime, clock_t listTime)
{
	if (vectorTime < listTime)
		std::cout << BLUE << "\n      std::vector was faster\n" << RESET;
	else if (listTime < vectorTime)
		std::cout << YELLOW << "\n      std::list was faster\n" << RESET;
}

bool has_duplicates(const std::vector<int>& numbers, int num) {
	for (size_t i = 0; i < numbers.size(); ++i) {
		if (numbers[i] == num)
			return (true);
	}
	return (false);
}

std::vector<int> ford_johnson_sort_vector(std::vector<int> v)
{
	if (v.size() <= 1)
		return v;
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}
	std::vector<int> remaining_elements;
	if (v.size() % 2 != 0)
		remaining_elements.push_back(v.back());
	std::vector<int> sorted_vector;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		sorted_vector.push_back(pairs[i].first);
	}
	std::sort(sorted_vector.begin(), sorted_vector.end());
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		std::vector<int>::iterator it = std::upper_bound(sorted_vector.begin(), sorted_vector.end(), pairs[i].second);
		sorted_vector.insert(it, pairs[i].second);
	}
	for (size_t i = 0; i < remaining_elements.size(); ++i)
	{
		std::vector<int>::iterator it = std::upper_bound(sorted_vector.begin(), sorted_vector.end(), remaining_elements[i]);
		sorted_vector.insert(it, remaining_elements[i]);
	}
	return (sorted_vector);
}

std::list<int> ford_johnson_sort_list(std::list<int> l)
{
	if (l.size() <= 1)
		return (l);
	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it = l.begin();
	while (std::distance(it, l.end()) > 1)
	{
		int first = *it;
		int second = *(++it);
		if (first > second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
		++it;
	}
	std::list<int> remaining_elements;
	if (it != l.end())
		remaining_elements.push_back(*it);
	std::list<int> sorted_list;
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
		sorted_list.push_back(pair_it->first);
	sorted_list.sort();
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
	{
		std::list<int>::iterator insert_pos = std::upper_bound(sorted_list.begin(), sorted_list.end(), pair_it->second);
		sorted_list.insert(insert_pos, pair_it->second);
	}
	for (std::list<int>::iterator remaining_it = remaining_elements.begin(); remaining_it != remaining_elements.end(); ++remaining_it)
	{
		std::list<int>::iterator insert_pos = std::upper_bound(sorted_list.begin(), sorted_list.end(), *remaining_it);
		sorted_list.insert(insert_pos, *remaining_it);
	}
	return (sorted_list);
}

