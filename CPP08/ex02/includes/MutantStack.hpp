/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:44:32 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/14 21:29:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() : std::stack<T>() { }
	MutantStack(const MutantStack& other) : std::stack<T>(other) { }
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
};

#endif