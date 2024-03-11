/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:39:37 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 14:35:51 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"
#include "./Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public AAnimal
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
