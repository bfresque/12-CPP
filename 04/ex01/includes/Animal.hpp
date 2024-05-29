/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:30:36 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:28:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include<iostream>
# include "./Brain.hpp"

# define LINE "--------------------------------"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void	makeSound() const;
		virtual Brain	*getBrain(void) const;
		std::string		getType() const;
};

#endif
