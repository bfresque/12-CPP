/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:32:43 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/14 21:13:55 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Span.hpp"

Span::Span() : _rangeSize(0) { }

Span::Span(unsigned int size) : _rangeSize(size) { }

Span::~Span() { }

void	Span::addNumber(unsigned int number) {
	if (_container.size() == _rangeSize)
		throw Span::numberAlreadySet();
	_container.push_back(number);
}

// int	Span::shortestSpan() const {
// 	if (_container.empty())
// 		throw Span::containerIsEmpty();
// 	else if (_container.size() == 1)
// 		throw Span::containerLengthIsOne();
// 	std::vector<int>copy = _container;
// 	std::sort(copy.begin(), copy.end(), std::less<int>());
// 	return *(copy.begin());
// }

// int	Span::longestSpan() const {
// 	if (_container.empty())
// 		throw Span::containerIsEmpty();
// 	else if (_container.size() == 1)
// 		throw Span::containerLengthIsOne();
// 	std::vector<int>copy = _container;
// 	std::sort(copy.begin(), copy.end(), std::greater<int>());
// 	return *(copy.begin());
// }

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
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}


template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	unsigned int rangeSize = std::distance(begin, end);
	if ((_container.size() + rangeSize) > _rangeSize)
		throw Span::numberAlreadySet();

	while (begin != end) {
		_container.push_back(*begin);
		++begin;
	}
}