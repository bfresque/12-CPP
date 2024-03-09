/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:39:37 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:24:00 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	private:
		Brain* _myBrain;
	protected:
		std::string type;
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog();
		void	makeSound() const;
		Brain	*getBrain(void) const;
};

#endif
