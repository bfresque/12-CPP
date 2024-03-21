/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:39:40 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 14:35:46 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"
#include "./Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public AAnimal
{
	private:
		Brain* _myBrain;
	protected:
		std::string type;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		~Cat();
		void	makeSound() const;
		Brain	*getBrain(void) const;
};

#endif