/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:39:40 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 10:15:44 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		~Cat();
		void	makeSound() const;
};

#endif
