/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:39:37 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 14:33:12 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	protected:
		std::string type;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog();
		void	makeSound() const;
};

#endif
