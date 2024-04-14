/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/14 18:29:25 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class NotFound : public std::exception {
	public:
		char const * what() const throw() {
			return "Number not found inside the container!";
		}
};

template <typename T>
int	*easyfind(T &container, int num) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw NotFound();
	return &(*it);
}
