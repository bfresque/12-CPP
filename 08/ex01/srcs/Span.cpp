/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:32:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/17 09:48:55 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Span.hpp"
# include <stdio.h>


Span::Span() : _rangeSize(0) { }

Span::Span(unsigned int N) : _rangeSize(N) { }

Span::Span(Span const & other) { *this = other; }

Span &Span::operator=(Span const & other) { _rangeSize = other._rangeSize; return (*this); }

Span::~Span() { }

void	Span::addNumber(unsigned int number) {
	if (_container.size() >= _rangeSize)
		throw Span::numberAlreadySet();
	_container.push_back(number);
}

int	Span::shortestSpan() const {
	if (_container.empty())
		throw Span::containerIsEmpty();
	else if (_container.size() == 1)
		throw Span::containerLengthIsOne();

	std::vector<int>copy = _container;
	std::sort(copy.begin(), copy.end());
	int shortest = INT_MAX;

	for (size_t i = 1; i < copy.size(); i++) {
		int diff = copy[i] - copy[i-1];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int	Span::longestSpan() const {
	if (_container.empty())
		throw Span::containerIsEmpty();
	else if (_container.size() == 1)
		throw Span::containerLengthIsOne();
	
	std::vector<int>copy = _container;
	int minSP = *std::min_element(copy.begin(), copy.end());
	int maxSP = *std::max_element(copy.begin(), copy.end());
	return (maxSP - minSP);
}
